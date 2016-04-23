#include "test.hh"
#include "list1.hh"
#include <iostream>

void Test::run(int Argc, char* Argv[]) {

List<int>* list_1 = new List<int>;
int numbers[]={10,100,1000,1000000,10000000};

std::cout<<"Test przeszukania listy."<<std::endl;

for(int i=0; i<5; i++)
list_1->test_on(numbers[i]);
std::cout<<"Koniec testu."<<std::endl;

}
