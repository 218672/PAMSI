#include <iostream>
#include "list.hh"
#include "stos.hh"

bool Stack::if_empty() const {
Node* v = head;
if (v!=NULL)
return true; // zwroc 1 jak nie pusty
else
return false; // zwroc 0 jak pusty
}

void Stack::add(int elem, int at) {
    Node* v = new Node; // nowy wezel
    v->elem=elem; // wpisujemy pozadany element
    v->next=head; // wskaznik na poczatek stosu
    head=v; // oznaczamy nowy poczatek stosu
}

void Stack::remove(int at) {
    if(if_empty()) {
        Node* old=head; // wzkaznik na poczatek
        head=old->next; // zmieniamy poczatek stosu
        delete old; // usuwamy pierwszy element
    }
    else
    std::cout<<"Stos jest pusty!"<<std::endl;
}

int Stack::size() {

return 1; // chwilowo
}

int Stack::get(int at) {

return 1; // chwilowo
}


