#include "neuron.hh"
#include <cstdlib>

Neuron::Neuron() {

error = 0.0;
input = 0.0;
output = 0.0;

}

Neuron::~Neuron() {

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
