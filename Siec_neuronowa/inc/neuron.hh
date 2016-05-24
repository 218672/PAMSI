#ifndef neuron_hh
#define neuron_hh

class Neuron {

private:

float weight;

float input;

float output;

public:

void set_weight(float weight);

float get_weight();

void set_input(float input);

float get_input();

void set_output(float output);

float get_output();

Neuron();

~Neuron();

};

#endif

