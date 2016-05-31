#include "test.hh"
#include "neuralnetwork.hh"
#define SIZE_OF_INPUT_LAYER 42
#define SIZE_OF_HIDDEN_LAYER 8
#define SIZE_OF_OUTPUT_LAYER 2
#include <vector>
#include <iostream>

void Test::run(int argc, char *argv[]) {

NeuralNetwork *ann = new NeuralNetwork(SIZE_OF_INPUT_LAYER, SIZE_OF_HIDDEN_LAYER, SIZE_OF_OUTPUT_LAYER);

std::vector<std::string> input_files;
std::vector<std::string> output_files;

int state;

input_files.push_back("0.dat");
input_files.push_back("1.dat");
input_files.push_back("2.dat");
input_files.push_back("3.dat");
input_files.push_back("4.dat");
input_files.push_back("5.dat");

output_files.push_back("out0.dat");
output_files.push_back("out1.dat");
output_files.push_back("out2.dat");
output_files.push_back("out3.dat");
output_files.push_back("out4.dat");
output_files.push_back("out5.dat");


while(1) {

if(state==4)
break;

std::cout<<"Co robimy?"<<std::endl<<std::endl;

std::cout<<"1. Wczytanie plików uczących."<<std::endl;
std::cout<<"2. Uczenie sieci."<<std::endl;
std::cout<<"3. Rozpoznawanie przykładowego zbioru 0-9"<<std::endl;
std::cout<<"4. Wyjście."<<std::endl;
std::cout<<"Twój wybór: ";

std::cin>>state;

    switch(state) {
        case 1:
        ann->load_training_set(input_files, output_files);
        break;
        case 2:
        ann->learn();
        break;
        case 3:
        ann->recognize(input_files);
        break;
        case 4:
        delete ann;
        break;
        default:
        std::cout<<"Zły wybór."<<std::endl;
        break;

    }

}

}
