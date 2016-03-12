#include <iostream>
#include "kolejka.hh"

using namespace std;

int main() { // sprawdzam sobie czy wszystko jest okej

    Queue<int>* my_queue = new Queue<int>;
    int state;
    const int elem=0; // dodajemy zera

    while(1) {
    cout<<endl;
    cout<<"Co chcesz zrobić?"<<endl;
    cout<<"1. Dodaj element z tylu"<<endl;
    cout<<"2. Usun element z przodu"<<endl;
    cout<<"3. Wyswietl kolejke"<<endl;
    cout<<"4. Zakoncz testy"<<endl;
    cout<<"Twoj wybor: ";
    cin>>state;
            switch(state) {
                case 1:
                my_queue->add_back(elem);
                break;
                case 2:
                my_queue->remove_front();
                break;
                case 3:
                my_queue->show_queue();
                break;
                case 4:
                cout<<"Do zobaczenia"<<endl;
                delete my_queue;
                return 0;
                default:
                cout<<"Zly wybor!"<<endl;
            }
    }
}
