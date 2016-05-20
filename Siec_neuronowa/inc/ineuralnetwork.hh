#ifndef ineuralnetwork_hh
#define ineuralnetwork_hh
#include "neuron.hh"

enum Layers {input, hidden, output};

class INeuralNetwork {

public:

virtual void add_neuron_to_layer(Neuron& neuron, Layers layer)=0;
virtual void learn(int input[], int output)=0;
virtual int recognize(int picture[])=0;

virtual ~INeuralNetwork() {}

};

#endif
