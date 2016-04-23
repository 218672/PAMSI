#include "test.hh"
#include <iostream>
#include "stack.hh"
#include "stack1.hh"

void Test::run(int Argc, char* Argv[]) {

Stack<int>* stack_1 = new Stack<int>;
int state[]={1,3,4,2,3,4,5}, elem[]={1,2,3,4,5};

std::cout<<"Test stosu."<<std::endl;

for(int k=0; k<7; k++) {

int st=state[k];

if(st==5) {
std::cout<<"Koniec testu!"<<std::endl;
delete stack_1;
break;
}

    switch(st) {
    case 1:
        for(int i=0; i<5; i++)
        stack_1->push(elem[i]);
        std::cout<<"Wpisano w stos wartości 1-5 w celu testu."<<std::endl;
        break;
    case 2:
        std::cout<<"Zdejmujemy wszystkie elementy ze stosu."<<std::endl;
        for(int i=0; i<5; i++) {
        try {
        std::cout<<"Zdjety element: "<<stack_1->pop()<<std::endl;
        }
        catch (std::string EmptyStackException) {
            std::cout<<EmptyStackException<<std::endl;
        }
        }
        break;
    case 3:
        std::cout<<"Sprawdzamy rozmiar."<<std::endl;
        std::cout<<"Rozmiar stosu: "<<stack_1->size()<<std::endl;
        break;
    case 4:
        std::cout<<"Wyświetlamy stos."<<std::endl;
        stack_1->show_stack();
        break;
    default:
        std::cout<<"Zly wybor!"<<std::endl;
        break;
    }
  }

}
