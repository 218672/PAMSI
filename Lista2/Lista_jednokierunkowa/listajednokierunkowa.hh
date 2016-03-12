#ifndef listajednokierunkowa_hh
#define listajednokierunkowa_hh

#include <iostream>
#include <string>


template <typename E>
class SNode;
template <typename E>
class SLinkedList;

template <typename E>
class SNode {
friend class SLinkedList<E>;

private:

E elem;
SNode<E>* next;

// metody dostepu do danych
E get_element() {
return elem;
}

SNode get_next() {
return next;
}

// metody modyfikujace
void set_element(E new_elem) {
elem=new_elem;
}

void set_next(SNode<E> new_node) {
next=new_node;
}

};

template <typename E>
class SLinkedList { // lista jednokierunkowa
public:
SLinkedList() {
head=NULL;
}; // konstruktor
~SLinkedList() {}; // destruktor
bool if_empty() const; // sprawdza czy lista jest pusta
const E& on_front() const; // zwraca pierwszy element
void add_front(const E& elem); // dodaje element na poczatek
void remove_front(); // usuwa element z poczatku
void add_back(const E& elem); // dodaje element na koniec
void remove_back();
void show_list() const;

private:
SNode<E>* head; // początek listy
};

template <typename E>
bool SLinkedList<E>::if_empty() const {
SNode<E>* v = head;
if (v!=NULL)
return true; // zwroc 1 jak nie pusta
else
return false; // zwroc 0 jak pusta
}

template <typename E>
void SLinkedList<E>::add_front(const E& elem) {
    SNode<E>* v = new SNode<E>; // nowy wezel
    v->elem=elem; // wpisujemy pozadany element
    v->next=head; // wskaznik na poczatek listy
    head=v; // oznaczamy nowy poczatek listy
}

template <typename E>
void SLinkedList<E>::remove_front() {
    if(if_empty()) {
        SNode<E>* old=head; // wzkaznik na poczatek
        head=old->next; // zmieniamy poczatek listy
        delete old; // usuwamy pierwszy element
    }
    else
    std::cout<<"Lista jest pusta!"<<std::endl;
}

template <typename E>
void SLinkedList<E>::add_back(const E& elem) {
    SNode<E>* v = new SNode<E>; // nowy wezel
    v->elem=elem; // wpisujemy pozadany element
    v->next=NULL; // wezel wskazuje na NULL
    SNode<E>* h = head; // wezel pomocniczy, wskazuje na poczatek listy
    if(if_empty()) { // sprawdzamy czy nie jest pusta
    while (h->next)
    h=h->next; // szukamy konca
    h->next=v; // wstawiamy na koniec
    }
    else
    head=v;
}

template <typename E>
void SLinkedList<E>::remove_back() {
    SNode<E>* v = head; // nowy wezel pokacujacy na poczatek
    if(if_empty()) { // tylko jesli nie jest pusta
        if(v->next) { // jak mamy cos oprocz startowego
            while(v->next->next)
            v=v->next; // szukamy przedostatniego
            delete v->next; // usuwamy ostatni
            v->next=NULL; // oznaczamy nowy koniec
        }
        else { // jesli jest tylko startowy
        delete v; // kasujemy startowy
        head=NULL; // lista staje sie pusta
        }
    }
    else
    std::cout<<"Lista jest pusta!"<<std::endl;
}

template <typename E>
void SLinkedList<E>::show_list() const {
    SNode<E>* v = head;
    if(if_empty()) {
    std::cout<<"Elementy listy: "<<std::endl;
        if(v->next) { // jesli jest wiecej niz jeden
            while(v->next) {
            std::cout<<v->elem<<std::endl;
            v=v->next;
            }
            std::cout<<v->elem<<std::endl;
        }
        else { // jesli jest jeden
            std::cout<<v->elem<<std::endl;
        }
    }
    else {
    std::cout<<"Lista jest pusta!"<<std::endl;
    }
}

#endif
