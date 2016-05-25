#ifndef neuron_hh
#define neuron_hh

class Neuron {

private:

float input;

float output;

float error;

public:


void set_input(float input);

float get_input();

void set_output(float output);

float get_output();

void set_error(float error);

float get_error();

Neuron();

~Neuron();

};

#endif
