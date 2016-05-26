  #include "neuralnetwork.hh"

#include <fstream>
#include <iostream>
#include <cmath>

#define MIN_DELTA 0.01
#define INPUT_LENGTH 784
#define OUTPUT_LENGTH 10
#define TRAINING_SET_SIZE 10000

NeuralNetwork::NeuralNetwork(int size_of_input_layer, int size_of_hidden_layer, int size_of_output_layer) {

pattern = new int[OUTPUT_LENGTH];
delta = new float* [3];

eta=0.1;
alfa=0.5;

delta[0] = new float [size_of_input_layer];
delta[1] = new float [size_of_hidden_layer];
delta[2] = new float [size_of_output_layer];

layer_sizes[0] = size_of_input_layer;
layer_sizes[1] = size_of_hidden_layer;
layer_sizes[2] = size_of_output_layer;

W = new float** [3];

W[0] = new float* [size_of_input_layer];
W[1] = new float* [size_of_hidden_layer];
W[2] = new float* [size_of_output_layer];

for(int i=0; i<size_of_input_layer; i++)
W[0][i] = new float [1];

for(int i=0; i<size_of_hidden_layer; i++)
W[1][i] = new float [size_of_input_layer];

for(int i=0; i<size_of_output_layer; i++)
W[2][i] = new float [size_of_hidden_layer];

W1 = new float** [3];

W1[0] = new float* [size_of_input_layer];
W1[1] = new float* [size_of_hidden_layer];
W1[2] = new float* [size_of_output_layer];

for(int i=0; i<size_of_input_layer; i++)
W1[0][i] = new float [1];

for(int i=0; i<size_of_hidden_layer; i++)
W1[1][i] = new float [size_of_input_layer];

for(int i=0; i<size_of_output_layer; i++)
W1[2][i] = new float [size_of_hidden_layer];

W2 = new float** [3];

W2[0] = new float* [size_of_input_layer];
W2[1] = new float* [size_of_hidden_layer];
W2[2] = new float* [size_of_output_layer];

for(int i=0; i<size_of_input_layer; i++)
W2[0][i] = new float [1];

for(int i=0; i<size_of_hidden_layer; i++)
W2[1][i] = new float [size_of_input_layer];

for(int i=0; i<size_of_output_layer; i++)
W2[2][i] = new float [size_of_hidden_layer];

for(int i=1;i<3;i++)
 for(int j=0;j<layer_sizes[i];j++)
  for(int k=0;k<=layer_sizes[i-1];k++)
  {
   W[i][j][k] =  (((rand() % 1000000L) / 1700.0) - 9.8)*0.0015;
   if(W[i][j][k] == 0.0) W[i][j][k] = 0.01492;
  }

layers = new Neurons[3];

layers[0].reserve(size_of_input_layer);
layers[1].reserve(size_of_hidden_layer);
layers[2].reserve(size_of_output_layer);


for(int i=0; i<size_of_input_layer; i++) {
    Neuron neuron;
    layers[0].push_back(neuron);
}


for(int i=0; i<size_of_hidden_layer; i++) {
    Neuron neuron;
    layers[1].push_back(neuron);
}

for(int i=0; i<size_of_output_layer; i++) {
    Neuron neuron;
    layers[2].push_back(neuron);
}


}

NeuralNetwork::~NeuralNetwork() {

delete [] pattern;

delete [] delta[0];
delete [] delta[1];
delete [] delta[2];

delete delta;

for(int i=0; i<layer_sizes[0]; i++)
delete [] W[0][i];

for(int i=0; i<layer_sizes[1]; i++)
delete [] W[1][i];

for(int i=0; i<layer_sizes[2]; i++)
delete [] W[2][i];

delete [] W[0];
delete [] W[1];
delete [] W[2];

delete [] W;

for(int i=0; i<layer_sizes[0]; i++)
delete [] W1[0][i];

for(int i=0; i<layer_sizes[1]; i++)
delete [] W1[1][i];

for(int i=0; i<layer_sizes[2]; i++)
delete [] W1[2][i];

delete [] W1[0];
delete [] W1[1];
delete [] W1[2];

delete [] W1;

for(int i=0; i<layer_sizes[0]; i++)
delete [] W2[0][i];

for(int i=0; i<layer_sizes[1]; i++)
delete [] W2[1][i];

for(int i=0; i<layer_sizes[2]; i++)
delete [] W2[2][i];

delete [] W2[0];
delete [] W2[1];
delete [] W2[2];

delete [] W2;

delete [] layers;

}

void NeuralNetwork::add_neuron_to_layer(Neuron& neuron, Layers layer) {

layers[layer].push_back(neuron);

}

void NeuralNetwork::learn_from_files(std::string input_data_file_name, std::string output_data_file_name) {

std::ifstream input_data;
std::ifstream output_data;

unsigned char pixel;
int input_value=0;
int output_value=0;

input_data.open(input_data_file_name, std::ios::binary);
output_data.open(output_data_file_name, std::ios::in);

if(input_data.good() && output_data.good()) {

    for(unsigned int i=0; i<TRAINING_SET_SIZE; i++) {

        for(unsigned int j=0; j<INPUT_LENGTH; j++) {

            input_data>>pixel;
            input_value = (float) pixel;
            (layers[0].at(j)).set_input(input_value);

        }

        for(unsigned int j=0; j<OUTPUT_LENGTH; j++) {

            output_data>>output_value;
            pattern[j]=output_value;

        }

        /*  Pojedyncze przetworzenie  */
        for(unsigned int j=1; j<3; j++) {

            for(unsigned int k=0; k<layers[j].size(); k++) {

                (layers[j].at(k)).set_input(0.0);

                for(unsigned int l=0; l<layers[j-1].size(); l++)
                (layers[j].at(k)).set_input( (layers[j].at(k)).get_input() + (layers[j-1].at(l)).get_output() * W[j][k][l] );

                (layers[j].at(k)).set_output(activation_function((layers[j].at(k)).get_input()));

            }

        }

        /*  Porownanie wartosci otrzymanych z oczekiwanymi  */
        for(unsigned int i=0;i<layers[2].size();i++)
        (layers[2].at(i)).set_error(pattern[i] - (layers[2].at(i)).get_output());

        /* Obliczanie błędów na neuronach */

        /* warstwa wyjściowa */
        for(unsigned int i=0; i<layers[2].size(); i++)
            delta[2][i] = (pattern[i]-(layers[2].at(i)).get_output()) * (layers[2].at(i)).get_output()*(1.0-(layers[2].at(i)).get_output());

        /* warstwa ukryta */
        for(unsigned int i=0; i<layers[1].size(); i++) {

            delta[1][i] = 0.0;
            for(unsigned int k=0; k<layers[2].size();k++)
            delta[1][i] += (layers[1].at(i)).get_output()*(1.0-(layers[1].at(i)).get_output()) * delta[2][k] * W[2][k][i];

        }

        /* Adaptacja wag */

        for(unsigned int i=1;i<3;i++) {
            for(unsigned int j=0;j<layers[i].size();j++) {
                for(unsigned int k=0; k<layers[i-1].size(); k++) {

                W2[i][j][k]  = W[i][j][k];
                W [i][j][k] += eta * delta[i][j] * (layers[i-1].at(k)).get_output() + alfa*(W[i][j][k]-W1[i][j][k]);
                W1[i][j][k]  = W2[i][j][k];

                }
            }
        }

        /* Obliczanie błędu sieci */

        for(unsigned int j=0;j<layers[2].size();j++) {

        RMS += ( (pattern[j] - (layers[2].at(j)).get_output()) * (pattern[j] - (layers[2].at(j)).get_output()) );
        ERMS = sqrt(RMS/(double)(OUTPUT_LENGTH*layers[2].size()));

        }

    }



    input_data.close();
    output_data.close();

}
else
std::cout<<"Nie uzyskano dostępu do plików uczących, uczenie przerwane."<<std::endl;


}

int NeuralNetwork::recognize(std::string test_data_file_name) {
  return 1;
}

float NeuralNetwork::activation_function(float input) {
  return 1.0/(1.0+exp(beta*((-1)*input)));
}
