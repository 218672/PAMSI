#include "test.hh"
#include "neuralnetwork.hh"
#define SIZE_OF_INPUT_LAYER 784
#define SIZE_OF_HIDDEN_LAYER 4
#define SIZE_OF_OUTPUT_LAYER 10

void Test::run(int argc, char *argv[]) {

NeuralNetwork *ann = new NeuralNetwork(SIZE_OF_INPUT_LAYER, SIZE_OF_HIDDEN_LAYER, SIZE_OF_OUTPUT_LAYER);

ann->learn_from_files("data1.bin", "out1.dat");

delete ann;

}
