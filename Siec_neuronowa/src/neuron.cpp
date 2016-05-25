#include "neuron.hh"
#include <cstdlib>

Neuron::Neuron(int size) {

for(int i=0;i<size;i++)
weight.push_back((((rand() % 1000000L) / 1700.0) - 9.8)*0.0015);

}

Neuron::~Neuron() {

}

void Neuron::set_weight(int number, float w) {

weight.at(number)=w;

}

float Neuron::get_weight(int number) {

return weight.at(number);

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

void Neuron::set_error(float error) {

this->error=error;

}

float Neuron::get_error() {

return error;

}
