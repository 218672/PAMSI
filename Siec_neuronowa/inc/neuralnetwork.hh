#ifndef neuralnetwork_hh
#define neuralnetwork_hh
#include "ineuralnetwork.hh"
#include "neuron.hh"
#include <vector>

typedef std::vector<Neuron> Neurons;

class NeuralNetwork : public INeuralNetwork {

private:

Neurons *layers;

int layer_sizes[3];

float ***W, ***W1, ***W2;

float beta, alfa, eta;

float **delta;

int *pattern;

float E;

float *test;

public:

void add_neuron_to_layer(Neuron& neuron, Layers layer);

void learn_from_files(std::vector<std::string> input_data_file_names, std::vector<std::string> output_data_file_names);

void recognize(std::vector<std::string> test_data_file_names);

float activation_function(float input);

NeuralNetwork(int size_of_input_layer, int size_of_hidden_layer, int size_of_output_layer);

~NeuralNetwork();

};

#endif
