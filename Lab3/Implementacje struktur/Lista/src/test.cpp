#include <iostream>
#include "list.hh"
#include "list1.hh"

int main() {

List<int>* list_1 = new List<int>;
int state, position;

std::cout<<"Test kolejki."<<std::endl;

while(1) {
std::cout<<std::endl;
std::cout<<"Co chcesz zrobic?"<<std::endl;
std::cout<<"1. Dodaj element"<<std::endl;
std::cout<<"2. Usun element"<<std::endl;
std::cout<<"3. Sprawdz rozmiar listy"<<std::endl;
std::cout<<"4. Wyjscie z programu"<<std::endl;
std::cout<<"Twoj wybor: ";
std::cin>>state;

    switch(state) {
    case 1:
        std::cout<<"Na ktora pozycje?"<<std::endl;
        std::cin>>position;
        try {
        list_1->add(0,position);
        }
        catch (std::string list_exceptions) {
        std::cout<<list_exceptions<<std::endl;
        }
        break;
    case 2:
        std::cout<<"Z ktorej pozycji? "<<std::endl;
        std::cin>>position;
        try {
        std::cout<<"Zdjety element: "<<list_1->remove(position)<<std::endl;
        }
        catch (std::string EmptyListException) {
            std::cout<<EmptyListException<<std::endl;
        }
        break;
    case 3:
        std::cout<<"Rozmiar listy: "<<list_1->size()<<std::endl;
        break;
    case 4:
        std::cout<<"Do widzenia!"<<std::endl;
        delete list_1;
        return 0;
    default:
        std::cout<<"Zly wybor!"<<std::endl;
        break;
    }
}

}
