#include "neuralnetwork.hh"

#include <fstream>
#include <iostream>
#include <cmath>

#define MIN_DELTA 0.01
#define INPUT_LENGTH 784
#define OUTPUT_LENGTH 10
#define TRAINING_SET_SIZE 10000

NeuralNetwork::NeuralNetwork(int size_of_input_layer, int size_of_hidden_layer, int size_of_output_layer) {

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
double delta=0;

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
            layers[2].at(j).set_input(output_value);

        }

        /***  Pojedyncze przetworzenie  ***/
        for(unsigned int j=1; j<3; j++) {

            for(unsigned int k=0; k<layers[j].size(); k++) {

                (layers[j].at(k)).set_input(0.0);

                for(unsigned int l=0; l<layers[j-1].size(); l++)
                (layers[j].at(k)).set_input( (layers[j].at(k)).get_input() + (layers[j-1].at(l)).get_output() * (layers[j].at(k)).get_weight() );

                (layers[j].at(k)).set_output(1.0/(1.0+exp(beta*((-1)*(layers[j].at(k)).get_input()))));

            }

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
