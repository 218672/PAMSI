#include "neuralnetwork.hh"

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

void NeuralNetwork::learn(int input[], int output) {

}

int NeuralNetwork::recognize(int picture[]) {

}
