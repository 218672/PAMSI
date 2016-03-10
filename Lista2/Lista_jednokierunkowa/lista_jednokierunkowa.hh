#include <iostream>
#include <string>

using namespace std;

template <typename E> class LinkedList;
template <typename E> class Node;

template <typename E>
class SNode {
friend class SLinkedList;

private:
E elem;
SNode<E>* next;

public:

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
~SLinkedList(); // destruktor
bool if_empty() const; // sprawdza czy lista jest pusta
const E& on_front() const; // zwraca pierwszy element
void add_front(const E& elem); // dodaje element na poczatek
void remove_front();

private:
SNode<E>* head; // początek listy
};


