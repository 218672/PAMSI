#include "test.hh"
#include "neuralnetwork.hh"
#define SIZE_OF_INPUT_LAYER 784
#define SIZE_OF_HIDDEN_LAYER 4
#define SIZE_OF_OUTPUT_LAYER 10
#include <vector>
#include <iostream>

void Test::run(int argc, char *argv[]) {

NeuralNetwork *ann = new NeuralNetwork(SIZE_OF_INPUT_LAYER, SIZE_OF_HIDDEN_LAYER, SIZE_OF_OUTPUT_LAYER);

std::vector<std::string> input_files;
std::vector<std::string> output_files;

int state;

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


while(1) {

if(state==3)
break;

std::cout<<"Co robimy?"<<std::endl<<std::endl;

std::cout<<"1. Uczenie sieci."<<std::endl;
std::cout<<"2. Rozpoznawanie przykładowego zbioru 0-9"<<std::endl;
std::cout<<"3. Wyjście."<<std::endl;
std::cout<<"Twój wybór: ";

std::cin>>state;

    switch(state) {
        case 1:
        ann->learn_from_files(input_files, output_files);
        break;
        case 2:
        ann->recognize(input_files);
        break;
        case 3:
        delete ann;
        break;
        default:
        std::cout<<"Zły wybór."<<std::endl;
        break;

    }

}

}
