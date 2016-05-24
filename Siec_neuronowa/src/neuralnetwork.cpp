#include "neuralnetwork.hh"

#include <cmath>

NeuralNetwork::NeuralNetwork(int size_of_input_layer, int size_of_hidden_layer, int size_of_output_layer) {

layers = new Neurons[3];

layers[0].reserve(size_of_input_layer);
layers[1].reserve(size_of_hidden_layer);
layers[2].reserve(size_of_output_layer);


for(int i=0; i<size_of_input_layer; i++) {
    Neuron neuron;
    layers[0].push_back(neuron);
}

for(int i=0; i<size_of_hidden_layer; i++) {
    Neuron neuron;
    layers[1].push_back(neuron);
}

for(int i=0; i<size_of_output_layer; i++) {
    Neuron neuron;
    layers[2].push_back(neuron);
}


}

NeuralNetwork::~NeuralNetwork() {

delete [] layers;

}

void NeuralNetwork::add_neuron_to_layer(Neuron& neuron, Layers layer) {

layers[layer].push_back(neuron);

}

void NeuralNetwork::learn_from_file(std::string file_name) {

  /***  Pojedyncze przetworzenie  ***/
  for(unsigned int i=1;i<layers->size();i++)
  {
    for(unsigned int j=0;j<layers[i].size();j++)
    {
      layers[i][j].set_input(0.0);
      for(unsigned int k=0;k<=layers[i-1].size();k++)
        layers[i][j].set_input(layers[i][j].get_input()+layers[i-1][k].get_output()*layers[i][j].get_weight());
      layers[i][j].set_output(1.0/(1.0+exp(beta*((-1)*layers[i][j].get_input()))));
    }
  }
}

int NeuralNetwork::recognize(int picture[]) {
  return 1;
}
