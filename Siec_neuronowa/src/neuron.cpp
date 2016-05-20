#include "neuron.hh"
#include <cstdlib>

Neuron::Neuron() {

weight=(((rand() % 1000000L) / 1700.0) - 9.8)*0.0015;

}

Neuron::~Neuron() {

}

void Neuron::set_weight(int weight) {

this->weight=weight;

}

int Neuron::get_weight() {

return weight;

}
