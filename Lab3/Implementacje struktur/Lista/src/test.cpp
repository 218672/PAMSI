#include <iostream>
#include "list.hh"
#include "list1.hh"
#include "timer.hh"

int main() {

List<int>* list_1 = new List<int>;
int state, position, elem;
int numbers;

std::cout<<"Test listy."<<std::endl;

while(1) {
std::cout<<std::endl;
std::cout<<"Co chcesz zrobic?"<<std::endl;
std::cout<<"1. Dodaj element"<<std::endl;
std::cout<<"2. Usun element"<<std::endl;
std::cout<<"3. Sprawdz rozmiar listy"<<std::endl;
std::cout<<"4. Elementy listy"<<std::endl;
std::cout<<"5. Test przeszukania"<<std::endl;
std::cout<<"6. Wyjscie z programu"<<std::endl;
std::cout<<"Twoj wybor: ";
std::cin>>state;

    switch(state) {
    case 1:
        std::cout<<"Wpisz element: ";
        std::cin>>elem;
        std::cout<<"Na ktora pozycje? ";
        std::cin>>position;
        try {
        list_1->add(elem,position);
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
        catch (std::string list_exceptions) {
            std::cout<<list_exceptions<<std::endl;
        }
        break;
    case 3:
        std::cout<<"Rozmiar listy: "<<list_1->size()<<std::endl;
        break;
    case 4:
        list_1->show_list();
        break;
    case 5:
        std::cout<<"Ile elementow ma miec przeszukiwana lista? ";
        std::cin>>numbers;
        list_1->test_on(numbers);
        break;
    case 6:
        std::cout<<"Do widzenia!"<<std::endl;
        delete list_1;
        return 0;
    default:
        std::cout<<"Zly wybor!"<<std::endl;
        break;
    }
}

}
