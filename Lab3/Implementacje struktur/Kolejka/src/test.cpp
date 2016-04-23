#include "test.hh"
#include <iostream>
#include "queue.hh"
#include "queue1.hh"

void Test::run(int Argc, char* Argv[]) {

Queue<int>* queue_1 = new Queue<int>;
int state[]={1,3,4,2,3,4,5}, elem[]={1,2,3,4,5};

std::cout<<"Test kolejki."<<std::endl;

for(int k=0; k<7; k++) {

int st=state[k];

if(st==5) {
std::cout<<"Koniec testu!"<<std::endl;
delete queue_1;
break;
}

    switch(st) {
    case 1:
        for(int i=0; i<5; i++)
        queue_1->add(elem[i]);
        std::cout<<"Wpisano w kolejkę wartości 1-5 w celu testu."<<std::endl;
        break;
    case 2:
        std::cout<<"Zdejmujemy wszystkie elementy z kolejki."<<std::endl;
        for(int i=0; i<5; i++) {
        try {
        std::cout<<"Zdjety element: "<<queue_1->remove()<<std::endl;
        }
        catch (std::string EmptyQueueException) {
            std::cout<<EmptyQueueException<<std::endl;
        }
        }
        break;
    case 3:
        std::cout<<"Sprawdzamy rozmiar."<<std::endl;
        std::cout<<"Rozmiar kolejki: "<<queue_1->size()<<std::endl;
        break;
    case 4:
        std::cout<<"Wyświetlamy kolejkę."<<std::endl;
        queue_1->show_queue();
        break;
    default:
        std::cout<<"Zly wybor!"<<std::endl;
        break;
    }

  }

}
