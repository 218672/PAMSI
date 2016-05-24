#ifndef neuron_hh
#define neuron_hh

class Neuron {

private:

double weight;
unsigned char value;

public:

void set_weight(double weight);

double get_weight();

void set_value(unsigned char value);

unsigned char get_value();

Neuron();

~Neuron();

};

#endif
