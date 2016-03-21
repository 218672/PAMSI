#include <iostream>
#include "struktura.hh"
#include "algorytmy.hh"

int main() {

Timer *tim = new Timer();
DataStructure *arr_1 = new Arr_first_type(10);
DataStructure *arr_2 = new Arr_second_type(10);
DataStructure *arr_3 = new Arr_third_type(10);

int numbers;
std::cout<<"Podaj ile liczb wpisac do tablicy: ";
std::cin>>numbers;

tim->tim_start();
for(int i=0; i<numbers; i++)
arr_2->add_num(0);
tim->tim_stop();
std::cout<<"Czas wykonania algorytmu n=2n dla "<<numbers<<" liczb wynosi: "<<tim->return_time()<<"ms"<<std::endl;

tim->tim_start();
for(int i=0; i<numbers; i++)
arr_3->add_num(0);
tim->tim_stop();
std::cout<<"Czas wykonania algorytmu n=n+100 dla "<<numbers<<" liczb wynosi: "<<tim->return_time()<<"ms"<<std::endl;

tim->tim_start();
for(int i=0; i<numbers; i++)
arr_1->add_num(0);
tim->tim_stop();
std::cout<<"Czas wykonania algorytmu n=n+1 dla "<<numbers<<" liczb wynosi: "<<tim->return_time()<<"ms"<<std::endl;

delete tim;
delete arr_1;
delete arr_2;
delete arr_3;
}
