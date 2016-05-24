#ifndef ineuralnetwork_hh
#define ineuralnetwork_hh
#include "neuron.hh"
#include <fstream>

enum Layers {input, hidden, output};

class INeuralNetwork {

public:

virtual void add_neuron_to_layer(Neuron& neuron, Layers layer)=0;
virtual void learn_from_files(std::string input_data_file_name, std::string output_data_file_name)=0;
virtual int recognize(std::string test_data_file_name)=0;

virtual ~INeuralNetwork() {}

};

#endif
