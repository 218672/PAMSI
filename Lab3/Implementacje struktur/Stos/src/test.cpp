#include <iostream>
#include "stack.hh"
#include "stack1.hh"

int main() {

Stack<int>* stack_1 = new Stack<int>;
int state, elem;

std::cout<<"Test stosu."<<std::endl;

while(1) {
std::cout<<std::endl;
std::cout<<"Co chcesz zrobic?"<<std::endl;
std::cout<<"1. Dodaj element"<<std::endl;
std::cout<<"2. Zdejmij element"<<std::endl;
std::cout<<"3. Sprawdz rozmiar stosu"<<std::endl;
std::cout<<"4. Pokaz stos"<<std::endl;
std::cout<<"5. Wyjscie z programu"<<std::endl;
std::cout<<"Twoj wybor: ";
std::cin>>state;

    switch(state) {
    case 1:
        std::cout<<"Wpisz element: ";
        std::cin>>elem;
        stack_1->push(elem);
        break;
    case 2:
        try {
        std::cout<<"Zdjety element: "<<stack_1->pop()<<std::endl;
        }
        catch (std::string EmptyStackException) {
            std::cout<<EmptyStackException<<std::endl;
        }
        break;
    case 3:
        std::cout<<"Rozmiar stosu: "<<stack_1->size()<<std::endl;
        break;
    case 4:
        stack_1->show_stack();
        break;
    case 5:
        std::cout<<"Do widzenia!"<<std::endl;
        delete stack_1;
        return 0;
    default:
        std::cout<<"Zly wybor!"<<std::endl;
        break;
    }
}

}
