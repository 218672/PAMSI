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

void learn_from_file(std::string file_name);

int recognize(int picture[]);

NeuralNetwork(int size_of_input_layer, int size_of_hidden_layer, int size_of_output_layer);

~NeuralNetwork();

};

#endif
