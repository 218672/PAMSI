#include <iostream>
#include "queue.hh"
#include "queue1.hh"

int main() {

Queue<int>* queue_1 = new Queue<int>;
int state;

std::cout<<"Test kolejki."<<std::endl;

while(1) {
std::cout<<std::endl;
std::cout<<"Co chcesz zrobic?"<<std::endl;
std::cout<<"1. Dodaj element"<<std::endl;
std::cout<<"2. Usun element"<<std::endl;
std::cout<<"3. Sprawdz rozmiar kolejki"<<std::endl;
std::cout<<"4. Wyjscie z programu"<<std::endl;
std::cout<<"Twoj wybor: ";
std::cin>>state;

    switch(state) {
    case 1:
        queue_1->add(0);
        break;
    case 2:
        try {
        std::cout<<"Zdjety element: "<<queue_1->remove()<<std::endl;
        }
        catch (std::string EmptyQueueException) {
            std::cout<<EmptyQueueException<<std::endl;
        }
        break;
    case 3:
        std::cout<<"Rozmiar kolejki: "<<queue_1->size()<<std::endl;
        break;
    case 4:
        std::cout<<"Do widzenia!"<<std::endl;
        delete queue_1;
        return 0;
    default:
        std::cout<<"Zly wybor!"<<std::endl;
        break;
    }
}

}
