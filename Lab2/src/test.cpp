#include "test.hh"
#include "struktura.hh"
#include "algorytmy.hh"
#include <iostream>

Test::~Test() {}

void Test::run(int Argc, char* Argv[]) {

int numbers[]={10, 100, 1000, 10000, 100000, 1000000};
int size_of_arr_numbers=6;

for(int k=0; k<size_of_arr_numbers; k++) {

Timer *tim = new Timer();
DataStructure *arr_1 = new Arr_first_type(10);
DataStructure *arr_2 = new Arr_second_type(10);
DataStructure *arr_3 = new Arr_third_type(10);

tim->tim_start();
for(int i=0; i<numbers[k]; i++)
arr_2->add_num(0);
tim->tim_stop();
std::cout<<"Czas wykonania algorytmu n=2n dla "<<numbers[k]<<" liczb wynosi: "<<tim->return_time()<<"ms"<<std::endl;

delete arr_2;

tim->tim_start();
for(int i=0; i<numbers[k]; i++)
arr_3->add_num(0);
tim->tim_stop();
std::cout<<"Czas wykonania algorytmu n=n+100 dla "<<numbers[k]<<" liczb wynosi: "<<tim->return_time()<<"ms"<<std::endl;

delete arr_3;

tim->tim_start();
for(int i=0; i<numbers[k]; i++)
arr_1->add_num(0);
tim->tim_stop();
std::cout<<"Czas wykonania algorytmu n=n+1 dla "<<numbers[k]<<" liczb wynosi: "<<tim->return_time()<<"ms"<<std::endl;

delete arr_1;

delete tim;

}

}
