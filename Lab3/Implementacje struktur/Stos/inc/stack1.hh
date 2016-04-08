#ifndef stack1_hh
#define stack1_hh
#include "stack.hh"

template <typename E>
class Node;
template <typename E>
class Stack;

template <typename E>
class Node { // wezel Stosu
friend class Stack<E>; // przyznajemy dostep klasie Stack

private:
E elem; // element wezla
Node<E>* next; // wskaznik na nastepny wezel

};

template <typename E>
class Stack : public IStack<E> {

private:
Node<E>* top; // szczyt stosu
int stack_size=0; // rozmiar stosu

public:
Stack() {
top=NULL;
};
~Stack() {}; 
void push(const E& elem); // dodaje element na szczyt stosu
E pop(); // zdejmuje i zwraca element ze szczytu stosu
int size(); // zwraca rozmiar stosu
void show_stack(); // wyswietla stos

};

template <typename E>
void Stack<E>::push(const E& elem) {
    Node<E>* v = new Node<E>; 
    v->elem=elem; 
    v->next=top; 
    top=v; 
    stack_size++; // zwiekszamy rozmiar stosu o 1
}

template <typename E>
E Stack<E>::pop() {
/* Metoda wyrzuca wyjatek gdy stos jest pusty */
    if(size()!=0) { // jesli stos nie jest pusty
        Node<E>* old=top; 
        top=old->next; 
        stack_size--; // zmniejszamy rozmiar stosu o 1
        return old->elem; // zwroc zdejmowany element
        delete old; // usuwamy pierwszy element
    }
    else {
        std::string EmptyStackException = "Stos jest pusty!";
        throw EmptyStackException; // metoda wyrzuca wyjatek jesli stos pusty
    }
}

template <typename E>
int Stack<E>::size() {
    return stack_size;
}

template <typename E>
void Stack<E>::show_stack() {
    Node<E>* tmp = top; 
    if(tmp!=NULL) { // jesli stos nie jest pusty
        std::cout<<"Elementy stosu: "<<std::endl;
        std::cout<<tmp->elem<<std::endl;
        while(tmp->next) { // wyswietlaj wszystkie
        tmp=tmp->next;
        std::cout<<tmp->elem<<std::endl;
        }
    }
    else
        std::cout<<"Stos jest pusty!"<<std::endl;
}


#endif
