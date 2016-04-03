#ifndef stack1_hh
#define stack1_hh
#include "stack.hh"

template <typename E>
class Node;
template <typename E>
class Stack;

template <typename E>
class Node {
friend class Stack<E>;

private:
E elem;
Node<E>* next;

};

template <typename E>
class Stack : public IStack<E> {

private:
Node<E>* top; // szczyt stosu

public:
Stack() { // konstruktor
top=NULL;
};
~Stack() {}; // destruktor
void push(const E& elem); // dodaje element na szczyt stosu
E pop(); // zdejmuje i zwraca element ze szczytu stosu
int size(); // zwraca rozmiar stosu

};

template <typename E>
void Stack<E>::push(const E& elem) {
    Node<E>* v = new Node<E>; // nowy wezel
    v->elem=elem; // wpisujemy pozadany element
    v->next=top; // wskaznik na poczatek stosu
    top=v; // oznaczamy nowy poczatek stosu
}

template <typename E>
E Stack<E>::pop() {
    if(size()!=0) {
        Node<E>* old=top; // wzkaznik na poczatek
        top=old->next; // zmieniamy poczatek stosu
        return old->elem;
        delete old; // usuwamy pierwszy element
    }
    else {
        std::string EmptyStackException = "Stos jest pusty!";
        throw EmptyStackException; // metoda wyrzuca wyjatek jesli stos pusty
    }
}

template <typename E>
int Stack<E>::size() {
    int counter=0;
    Node<E>* tmp = top;
    if(tmp!=NULL) {
        counter++;
        while(tmp->next) {
        tmp=tmp->next;
        counter++;
        }
    return counter;
    }
    else
        return 0;
}



#endif
