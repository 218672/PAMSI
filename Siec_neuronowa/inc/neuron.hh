#ifndef neuron_hh
#define neuron_hh

#include <vector>

class Neuron {

private:

std::vector<float> weight;

float input;

float output;

float error;

public:

void set_weight(int number, float w);

float get_weight(int number);

void set_input(float input);

float get_input();

void set_output(float output);

float get_output();

void set_error(float error);

float get_error();

Neuron(int size);

~Neuron();

};

#endif
