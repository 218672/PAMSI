#include <iostream>
#include "deque.hh"

using namespace std;

bool is_pal(Deque<char>* new_deq) {
    Deque<char>* check_pal = new_deq;
    if(check_pal->size()<=1)
    return true;
    else if(check_pal->size()>1 && (check_pal->on_front()==check_pal->on_back())) {
    check_pal->remove_front();
    check_pal->remove_back();
    is_pal(check_pal);
    }
    else
    return false;
}

int main() { // sprawdzam sobie czy wszystko jest okej

    Deque<char>* my_deque = new Deque<char>;
    int state, state2;
    const char elem='a', elem1='a'; // dodajemy a, jesli dodano na front lub b jesli dodano na back
    string pal;

    cout<<"Test kolejki czy sparwdzanie palindromow?"<<endl;
    cout<<"1. Test kolejki"<<endl;
    cout<<"2. Sprawdzanie palindromow"<<endl;
    cin>>state2;
    switch(state2) {

    case 1:

    while(1) {
    cout<<endl;
    cout<<"Co chcesz zrobić?"<<endl;
    cout<<"1. Dodaj element z przodu"<<endl;
    cout<<"2. Dodaj element z tylu"<<endl;
    cout<<"3. Usun element z przodu"<<endl;
    cout<<"4. Usun element z tylu"<<endl;
    cout<<"5. Wyswietl kolejke"<<endl;
    cout<<"6. Podaj rozmiar kolejki"<<endl;
    cout<<"7. Zakoncz testy"<<endl;
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
                cout<<my_deque->size()<<endl;
                break;
                case 7:
                cout<<"Do zobaczenia"<<endl;
                delete my_deque;
                return 0;
                default:
                cout<<"Zly wybor!"<<endl;
            }
    }
    break;

    case 2:
    cout<<"Wpisz slowko: "<<endl;
    cin>>pal;

    for(unsigned int i=0;i<pal.size();i++) {
    const char element=pal[i];
    my_deque->add_front(element);
    }

    if(is_pal(my_deque))
    cout<<"To jest palindrom"<<endl;
    else
    cout<<"To nie jest palindrom"<<endl;

    delete my_deque;
    return 0;

    }
}
