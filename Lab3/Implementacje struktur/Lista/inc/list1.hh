#ifndef list1_hh
#define list1_hh
#include "list.hh"

template <typename E>
class Node;
template <typename E>
class List;

template <typename E>
class Node {
friend class List<E>;

private:
E elem;
Node<E>* next;

};

template <typename E>
class List : public IList<E> {

private:
Node<E>* front;
Node<E>* end;

public:
List() { // konstruktor
front = NULL;
end = NULL;
};
~List() {}; // destruktor
void add(const E& elem, int i); // dodaje element na wybranym miejscu listy, wyrzuca wyjatek jesli nie ma takiego elementu
E remove(int i); // zdejmuje element z wybranego miejsca listy, wyrzuca wyjątek jeśli nie ma takiego elementu lub lista jest pusta
int size(); // zwraca rozmiar listy

};

template <typename E>
void List<E>::add(const E& elem, int i) {
    Node<E>* v = new Node<E>; // nowy wezel pomocniczy, ktory chcemy wkleic do listy
    Node<E>* tmp = new Node<E>; // nowy wezel pomocniczy
    v->elem=elem; // wpisujemy pozadany element

    if(i>=1 && i<size()+1 && size()!=0) { // jesli nie na pierwsze miejsce i nie dalej niz rozmiar+1
    Node<E>* f = front; // wezel pomocniczy, wskazuje na poczatek listy
    for(int j=1; j<i; j++)
    f=f->next; // szukamy wybranego miejsca
    tmp=f->next;
    f->next=v;
    v->next=tmp;
    }
    else if(i==1 && (size()==0)) {
    front=v;
    end=v;
    }
    else if(i==size()+1 && size()>=1) {
    Node<E>* e = end; // wezel pomocniczy, wskazuje na koniec listy
    if(size()!=0) { // sprawdzamy czy nie jest pusta
    e->next=v;
    end=v;
    }
    }
    else {
    std::string WrongListIndexException = "Lista nie ma takiego pola, sprawdz najpierw rozmiar!";
    throw WrongListIndexException; // wyrzuca wyjatek jesli blednie wpisano pole
    }


}

template <typename E>
E List<E>::remove(int i) {
    if(i==1) {
    if(size()!=0) {
        Node<E>* old=front; // wzkaznik na poczatek
        front=old->next; // zmieniamy poczatek listy
        return old->elem;
        delete old; // usuwamy pierwszy element
    }
    else {
    std::string EmptyListException = "Lista jest pusta!";
    throw EmptyListException;
    }
    }
    else if(i==size() && size()!=1) {
    Node<E>* v = front; // nowy wezel pokacujacy na poczatek
    Node<E>* e = end;
    if(size()!=0) { // tylko jesli nie jest pusta
            return e->elem;
            delete e;
            while(v->next->next)
            v=v->next; // szukamy przedostatniego
            v->next=NULL; // oznaczamy nowy koniec
            end=v;
    }
    else {
    std::string EmptyListException = "Lista jest pusta!";
    throw EmptyListException;
    }
    }
    else if(i>1 && i<size()) {
    Node<E>* v = front; // nowy wezel pokacujacy na poczatek
    if(size()!=0) { // tylko jesli nie jest pusta
            for(int j=1; j<i; j++)
            v=v->next;
            return v->next->elem;
            Node<E>* tmp = v->next->next;
            v->next=tmp;
            delete v->next;
    }
    else {
    std::string EmptyListException = "Lista jest pusta!";
    throw EmptyListException;
    }
    }
    else {
    std::string WrongListIndexException = "Lista nie ma takiego pola, pamietaj o numeracji!";
    throw WrongListIndexException;
    }
}

template <typename E>
int List<E>::size() {
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
