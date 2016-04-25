#include "test.hh"
#include "tree.hh"
#include "timer.hh"
#include <iostream>

void Test::run(int Argc, char* Argv[]) {

    Timer* tim = new Timer();
    RBTree *tree;
    int *help_arr;

    int amount_of_data[]={10,100,1000,10000,100000,1000000};

    std::cout<<"Test operacji na drzewie czerwono czarnym."<<std::endl<<std::endl;

    for(int k=0; k<6; k++) {

    tree = new RBTree();
    help_arr = new int [amount_of_data[k]];


    for(int j=0; j<amount_of_data[k]; j++)
    help_arr[k]=(rand()%1000000);

    tim->tim_start();
    for(int i=0; i<amount_of_data[k]; i++)
    tree->add(help_arr[i]);
    tim->tim_stop();
    std::cout<<"Czas dodania "<<amount_of_data[k]<<" losowych liczb do drzewa wynosi "<<tim->return_time()<<"ms."<<std::endl<<std::endl;


    tim->tim_start();
    for(int i=0; i<amount_of_data[k]; i++) {
    try {
    tree->find(-1);
    }
    catch(const char* Exception) {

    }
    }
    tim->tim_stop();
    std::cout<<"Czas przeszukania drzewa "<<amount_of_data[k]<<" elementów wynosi "<<tim->return_time()<<"ms."<<std::endl<<std::endl;

    delete tree;
    delete help_arr;

    }

    delete tim;

}
