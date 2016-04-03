#ifndef queue1_hh
#define queue1_hh
#include "queue.hh"

template <typename E>
class Node;
template <typename E>
class Queue;

template <typename E>
class Node {
friend class Queue<E>;

private:
E elem;
Node<E>* next;

};

template <typename E>
class Queue : public IQueue<E> {

private:
Node<E>* front;
Node<E>* end;

public:
Queue() { // konstruktor
front = NULL;
end = NULL;
};
~Queue() {}; // destruktor
void add(const E& elem); // dodaje element na tyl kolejki
E remove(); // zdejmuje element z poczatku kolejki, wyrzuca wyjatek jesli pusta
int size(); // zwraca rozmiar kolejki

};

template <typename E>
void Queue<E>::add(const E& elem) {
    Node<E>* v = new Node<E>; // nowy wezel
    v->elem=elem; // wpisujemy pozadany element
    v->next=NULL; // wezel wskazuje na NULL
    Node<E>* e = end; // wezel pomocniczy, wskazuje na koniec kolejki
    if(size()!=0) { // sprawdzamy czy nie jest pusta
    e->next=v;
    end=v;
    }
    else {
    front=v;
    end=v;
    }
}

template <typename E>
E Queue<E>::remove() {
    if(size()!=0) {
        Node<E>* old=front; // wzkaznik na poczatek
        front=old->next; // zmieniamy poczatek kolejki
        return old->elem; // zwracamy pierwszy element
        delete old; // usuwamy pierwszy element
    }
    else {
    std::string EmptyQueueException = "Kolejka jest pusta!";
    throw EmptyQueueException; // metoda wyrzuca wyjatek jesli kolejka pusta
    }
}

template <typename E>
int Queue<E>::size() {
    int counter=0;
    Node<E>* tmp = front;
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
