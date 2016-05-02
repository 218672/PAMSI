#include "queue.hh"
#include <iostream>

Queue() {
front = NULL; // inicjalizacja NULLami poczatku i konca
end = NULL;
}

Queue::~Queue {}

void Queue::add(const int& elem) {
    QNode* v = new QNode;
    v->elem=elem;
    v->next=NULL;
    QNode* e = end;
    if(size()!=0) { // sprawdzamy czy nie jest pusta
    e->next=v;
    end=v;
    queue_size++; // zwiekszamy rozmiar kolejki o 1
    }
    else {
    front=v; // ustawiamy nowy poczatek i nowy koniec
    end=v;
    queue_size++; // zwiekszamy rozmiar kolejki o 1
    }
}

int Queue::remove() {
/* Wyrzuca wyjątek gdy kolejka jest pusta */
    if(size()!=0) {
        QNode* old=front;
        front=old->next;
        queue_size--; // zmniejszamy rozmiar kolejki o 1
        return old->elem; // zwracamy pierwszy element
        delete old;
    }
    else {
    std::string EmptyQueueException = "Kolejka jest pusta!";
    throw EmptyQueueException; // metoda wyrzuca wyjatek jesli kolejka pusta
    }
}

int Queue::size() {
    return queue_size;
}

void Queue::show_queue() {
    QNode* tmp = front;
    if(tmp!=NULL) {
        std::cout<<"Elementy kolejki:"<<std::endl;
        std::cout<<tmp->elem<<std::endl;
        while(tmp->next) { // wyswietlamy elementy
        tmp=tmp->next;
        std::cout<<tmp->elem<<std::endl;
        }
    }
    else
        std::cout<<"Kolejka jest pusta!"<<std::endl;
}
