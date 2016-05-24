#ifndef neuralnetwork_hh
#define neuralnetwork_hh
#include "ineuralnetwork.hh"
#include "neuron.hh"
#include <vector>

typedef std::vector<Neuron> Neurons;

class NeuralNetwork : public INeuralNetwork {

private:

Neurons *layers;

float beta;

public:

void add_neuron_to_layer(Neuron& neuron, Layers layer);

void learn_from_files(std::string input_data_file_name, std::string output_data_file_name);

int recognize(std::string test_data_file_name);

NeuralNetwork(int size_of_input_layer, int size_of_hidden_layer, int size_of_output_layer);

~NeuralNetwork();

};

#endif
