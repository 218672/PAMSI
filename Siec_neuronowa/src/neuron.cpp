#include "neuron.hh"
#include <cstdlib>

Neuron::Neuron() {

weight=(((rand() % 1000000L) / 1700.0) - 9.8)*0.0015;

}

Neuron::~Neuron() {

}

void Neuron::set_weight(float weight) {

this->weight=weight;

}

float Neuron::get_weight() {

return weight;

}

void Neuron::set_input(float input) {

this->input=input;

}

float Neuron::get_input() {

return input;

}

void Neuron::set_output(float output) {

this->output=output;

}

float Neuron::get_output() {

return output;

}
