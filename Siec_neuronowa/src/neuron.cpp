#include "neuron.hh"
#include <cstdlib>

Neuron::Neuron() {

weight=(((rand() % 1000000L) / 1700.0) - 9.8)*0.0015;

value='0';

}

Neuron::~Neuron() {

}

void Neuron::set_weight(double weight) {

this->weight=weight;

}

double Neuron::get_weight() {

return weight;

}

void Neuron::set_value(unsigned char value) {

this->value=value;

}

unsigned char Neuron::get_value() {

return value;

}
