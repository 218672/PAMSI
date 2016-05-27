#include "test.hh"
#include "neuralnetwork.hh"
#define SIZE_OF_INPUT_LAYER 784
#define SIZE_OF_HIDDEN_LAYER 4
#define SIZE_OF_OUTPUT_LAYER 10
#include <vector>

void Test::run(int argc, char *argv[]) {

NeuralNetwork *ann = new NeuralNetwork(SIZE_OF_INPUT_LAYER, SIZE_OF_HIDDEN_LAYER, SIZE_OF_OUTPUT_LAYER);

std::vector<std::string> input_files;
std::vector<std::string> output_files;

input_files.push_back("data0.bin");
input_files.push_back("data1.bin");
input_files.push_back("data2.bin");
input_files.push_back("data3.bin");
input_files.push_back("data4.bin");
input_files.push_back("data5.bin");
input_files.push_back("data6.bin");
input_files.push_back("data7.bin");
input_files.push_back("data8.bin");
input_files.push_back("data9.bin");

output_files.push_back("out0.dat");
output_files.push_back("out1.dat");
output_files.push_back("out2.dat");
output_files.push_back("out3.dat");
output_files.push_back("out4.dat");
output_files.push_back("out5.dat");
output_files.push_back("out6.dat");
output_files.push_back("out7.dat");
output_files.push_back("out8.dat");
output_files.push_back("out9.dat");

ann->learn_from_files(input_files, output_files);

delete ann;

}
