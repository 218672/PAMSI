  #include "neuralnetwork.hh"

#include <fstream>
#include <iostream>
#include <cmath>

#define MIN_ERMS 0.096
#define INPUT_LENGTH 784
#define OUTPUT_LENGTH 10

NeuralNetwork::NeuralNetwork(int size_of_input_layer, int size_of_hidden_layer, int size_of_output_layer) {

pattern = new int[OUTPUT_LENGTH];
delta = new float* [3];

eta=0.1;
alfa=0.6;
beta=0.9;

delta[0] = new float [size_of_input_layer];
delta[1] = new float [size_of_hidden_layer];
delta[2] = new float [size_of_output_layer];

layer_sizes[0] = size_of_input_layer;
layer_sizes[1] = size_of_hidden_layer;
layer_sizes[2] = size_of_output_layer;

W = new float** [3];

for(int i=0; i<3; i++) {

W[i] = new float* [layer_sizes[i]];

    for(int j=0; j<layer_sizes[i]; j++) {

    if(i==0)
    W[i][j] = new float [1];
    else
    W[i][j] = new float [layer_sizes[i-1]];

    }
}

W1 = new float** [3];

for(int i=0; i<3; i++) {

W1[i] = new float* [layer_sizes[i]];

    for(int j=0; j<layer_sizes[i]; j++) {

    if(i==0)
    W1[i][j] = new float [1];
    else
    W1[i][j] = new float [layer_sizes[i-1]];

    }
}

W2 = new float** [3];

for(int i=0; i<3; i++) {

W2[i] = new float* [layer_sizes[i]];

    for(int j=0; j<layer_sizes[i]; j++) {

    if(i==0)
    W2[i][j] = new float [1];
    else
    W2[i][j] = new float [layer_sizes[i-1]];

    }
}

for(int i=1; i<3;i++) {
    for(int j=0; j<layer_sizes[i]; j++) {
        for(int k=0; k<layer_sizes[i-1]; k++) {

            W[i][j][k] =  (((rand() % 1000000L) / 1700.0) - 9.8)*0.0015;
            if(W[i][j][k] == 0.0)
            W[i][j][k] = 0.01492;

        }
    }
}

layers = new Neurons[3];


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

void NeuralNetwork::learn_from_files(std::vector<std::string> input_data_file_names, std::vector<std::string> output_data_file_names) {

std::ifstream input_data;
std::ifstream output_data;

unsigned char pixel;
int input_value = 0;
int output_value = 0;
int ages = 0;

int learning_vectors = 10; //Ilosc wektorow uczacych

do {

for(int f=0; f<10; f++) {

    input_data.open(input_data_file_names.at(f), std::ios::binary);
    output_data.open(output_data_file_names.at(f), std::ios::in);

    if(input_data.good() && output_data.good()) {

            for(unsigned int j=0; j<INPUT_LENGTH; j++) {

            input_data>>pixel;
            input_value = (float) pixel;
            if(input_value>0)
            input_value=1;
            (layers[0].at(j)).set_input(input_value);
            (layers[0].at(j)).set_output(input_value);

            }

            for(unsigned int j=0; j<OUTPUT_LENGTH; j++) {

            output_data>>output_value;
            pattern[j]=output_value;

            }

    //std::cout<<"Rozpoczęto uczenie wektorów przedstawiających cyfrę "<<f<<"..."<<std::endl<<std::endl;



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
            for(unsigned int j=0; j<layers[2].size(); j++)
                layers[2].at(j).set_error(pattern[j] - (layers[2].at(j)).get_output());


            /* Obliczanie błędów na neuronach */

            /* warstwa wyjściowa */
            for(unsigned int j=0; j<layers[2].size(); j++)
                delta[2][j] = (pattern[j]-(layers[2].at(j)).get_output()) * (layers[2].at(j)).get_output() * (1.0-(layers[2].at(j)).get_output());

            /* warstwa ukryta */
            for(unsigned int j=0; j<layers[1].size(); j++) {

            delta[1][j] = 0.0;

            for(unsigned int k=0; k<layers[2].size();k++)
                delta[1][j] += (layers[1].at(j)).get_output()*(1.0-(layers[1].at(j)).get_output()) * delta[2][k] * W[2][k][j];

            }

        /* Adaptacja wag */

            for(unsigned int j=1;j<3;j++) {
                for(unsigned int k=0;k<layers[j].size();k++) {
                    for(unsigned int l=0; l<layers[j-1].size(); l++) {

                    W2[j][k][l]  = W[j][k][l];
                    W [j][k][l] += eta * delta[j][k] * (layers[j-1].at(l)).get_output() + alfa*(W[j][k][l]-W1[j][k][l]);
                    W1[j][k][l]  = W2[j][k][l];

                    }
                }
            }


    //std::cout<<"Zakończono uczenie wektorów przedstawiających cyfrę "<<f<<"..."<<std::endl<<std::endl;
    // koniec wektora uczącego

    input_data.close();
    output_data.close();

}
    else
    std::cout<<"Nie uzyskano dostępu do plików uczących, uczenie przerwane."<<std::endl;
}

        ages++;

        std::cout<<"Numer aktualnej epoki uczącej: "<<ages<<std::endl;

         /* Obliczanie błędu sieci dla epoki */
        RMS=0;
        for(unsigned int j=0;j<layers[2].size();j++)
        RMS += ( (pattern[j] - (layers[2].at(j)).get_output()) * (pattern[j] - (layers[2].at(j)).get_output()) );
        ERMS = sqrt(RMS/((float)(learning_vectors*layers[2].size())));
        std::cout<<"ERMS: "<<ERMS<<std::endl;

} // koniec epoki
while(ERMS>=MIN_ERMS);


}

void NeuralNetwork::recognize(std::vector<std::string> test_data_file_names) {

  std::ifstream test_data;
  unsigned char pixel;
  int test_value;
  float output = 0.0;
  int number = 0;


for(int f=0; f<10; f++) {

    test_data.open(test_data_file_names.at(f), std::ios::binary);

    if(test_data.good()) {

    for(int i=0; i<2; i++)
    for(unsigned int j=0; j<INPUT_LENGTH; j++) {

    test_data>>pixel;
    test_value = (float) pixel;
    if(test_value>0)
    test_value=1;
    (layers[0].at(j)).set_input(test_value);
    (layers[0].at(j)).set_output(test_value);

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

      for(unsigned int i=0; i<layers[2].size(); i++) {
      std::cout<<layers[2].at(i).get_output()<<" ";
        if((layers[2].at(i)).get_output()>output) {
        output=(layers[2].at(i)).get_output();
        number=i;
        }
      }

      std::cout<<"Rozpoznano cyfre: "<<number<<std::endl<<std::endl;

    output = 0.0;
    number = 0;

    test_data.close();

  }
  else
  std::cout<<"Nie można otworzyć pliku z danymi do testowania, przerwano."<<std::endl;
}

}

float NeuralNetwork::activation_function(float input) {
  return 1.0/(1.0+exp(beta*((-1)*input)));
}
