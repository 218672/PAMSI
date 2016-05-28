#ifndef ineuralnetwork_hh
#define ineuralnetwork_hh
#include "neuron.hh"
#include <fstream>
#include <vector>

enum Layers {input, hidden, output};

class INeuralNetwork {

public:

virtual void add_neuron_to_layer(Neuron& neuron, Layers layer)=0;

virtual void learn_from_files(std::vector<std::string> input_data_file_names, std::vector<std::string> output_data_file_names)=0;

virtual void recognize(std::vector<std::string> test_data_file_names)=0;

virtual ~INeuralNetwork() {}

};

#endif
