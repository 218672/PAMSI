#ifndef stack1_hh
#define stack1_hh
#include "list.hh"

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
class Stack : public IList<E> {

private:
Node<E>* head; // góra stosu
int get(int at=0); // funkcja bezuzyteczna, nie uzywamy, at jako bezuzyteczny w stosie parametr jest ustawiany jako domyslny, nie wpisujemy go w wywolaniu

public:
Stack() {
head=NULL;
}

void add(E elem, int at=0); // to samo tutaj z parametrem at, nawet wywolany nie zrobi niczego
void remove(int at=0); // i tu tez
int size();
bool if_empty() const;


};


template <typename E>
bool Stack<E>::if_empty() const {
Node<E>* v = head;
if (v!=NULL)
return true; // zwroc 1 jak nie pusty
else
return false; // zwroc 0 jak pusty
}

template <typename E>
void Stack<E>::add(E elem, int at) {
    Node<E>* v = new Node<E>; // nowy wezel
    v->elem=elem; // wpisujemy pozadany element
    v->next=head; // wskaznik na poczatek stosu
    head=v; // oznaczamy nowy poczatek stosu
}

template <typename E>
void Stack<E>::remove(int at) {
    if(if_empty()) {
        Node<E>* old=head; // wzkaznik na poczatek
        head=old->next; // zmieniamy poczatek stosu
        delete old; // usuwamy pierwszy element
    }
    else
    std::cout<<"Stos jest pusty!"<<std::endl;
}

template <typename E>
int Stack<E>::size() {

return 1; // chwilowo
}

template <typename E>
int Stack<E>::get(int at) {

return 1; // chwilowo
}


#endif
