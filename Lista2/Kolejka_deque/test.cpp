#include <iostream>
#include "deque.hh"

using namespace std;

int main() { // sprawdzam sobie czy wszystko jest okej

    Deque<int>* my_deque = new Deque<int>;
    int state;
    const int elem=0, elem1=1; // dodajemy zera, jesli dodano na front lub 1 jesli dodano na back

    while(1) {
    cout<<endl;
    cout<<"Co chcesz zrobić?"<<endl;
    cout<<"1. Dodaj element z przodu"<<endl;
    cout<<"2. Dodaj element z tylu"<<endl;
    cout<<"3. Usun element z przodu"<<endl;
    cout<<"4. Usun element z tylu"<<endl;
    cout<<"5. Wyswietl kolejke"<<endl;
    cout<<"6. Zakoncz testy"<<endl;
    cout<<"Twoj wybor: ";
    cin>>state;
            switch(state) {
                case 1:
                my_deque->add_front(elem);
                break;
                case 2:
                my_deque->add_back(elem1);
                break;
                case 3:
                my_deque->remove_front();
                break;
                case 4:
                my_deque->remove_back();
                break;
                case 5:
                my_deque->show_deque();
                break;
                case 6:
                cout<<"Do zobaczenia"<<endl;
                delete my_deque;
                return 0;
                default:
                cout<<"Zly wybor!"<<endl;
            }
    }
}
