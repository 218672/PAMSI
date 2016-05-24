#include "neuralnetwork.hh"
#include <fstream>
#include <iostream>
#define MIN_DELTA 0.01
#define X_LENGTH 28

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

delete []layers;

}

void NeuralNetwork::add_neuron_to_layer(Neuron& neuron, Layers layer) {

layers[layer].push_back(neuron);

}

void NeuralNetwork::learn_from_files(std::string input_data_file_name, std::string output_data_file_name) {

std::ifstream input_data;
std::ifstream output_data;

char pixel_buffer[sizeof(unsigned char)];
unsigned char pixel;
int output_value=0;
double delta=0;

input_data.open(input_data_file_name, std::ios::binary);
output_data.open(output_data_file_name, std::ios::in);

if(input_data.good() && output_data.good()) {



    while(/*delta>MIN_DELTA ||*/ output_data>>output_value) {

        for(int i=0; i<X_LENGTH*X_LENGTH; i++) {
            input_data.read(pixel_buffer, sizeof(unsigned char));
            pixel = (unsigned char) pixel_buffer;
            std::cout<<pixel<<"<--Wejscie ";
            (layers[0].at(i)).set_value(pixel);
        }

            std::cout<<output_value<<"<--Wyjscie ";

    }

    input_data.close();
    output_data.close();

}
else
std::cout<<"Nie uzyskano dostępu do plików uczących, uczenie przerwane."<<std::endl;


}

int NeuralNetwork::recognize(std::string test_data_file_name) {

}
