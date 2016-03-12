#ifndef kolejka_hh
#define kolejka_hh

template <typename E>
class SNode;
template <typename E>
class Queue;

template <typename E>
class SNode {
friend class Queue<E>;

public:

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
class Queue { // kolejka
public:
Queue() {
head=NULL;
}; // konstruktor
~Queue() {}; // destruktor
bool if_empty() const; // sprawdza czy kolejka jest pusta
const E& on_front() const; // zwraca pierwszy element
void remove_front(); // usuwa element z poczatku
void add_back(const E& elem); // dodaje element na koniec
void show_queue() const;

private:
SNode<E>* head; // początek kolejki
};

template <typename E>
bool Queue<E>::if_empty() const {
SNode<E>* v = head;
if (v!=NULL)
return true; // zwroc 1 jak nie pusta
else
return false; // zwroc 0 jak pusta
}

template <typename E>
void Queue<E>::remove_front() {
    if(if_empty()) {
        SNode<E>* old=head; // wzkaznik na poczatek
        head=old->next; // zmieniamy poczatek listy
        delete old; // usuwamy pierwszy element
    }
    else
    std::cout<<"Kolejka jest pusta!"<<std::endl;
}

template <typename E>
void Queue<E>::add_back(const E& elem) {
    SNode<E>* v = new SNode<E>; // nowy wezel
    v->elem=elem; // wpisujemy pozadany element
    v->next=NULL; // wezel wskazuje na NULL
    SNode<E>* h = head; // wezel pomocniczy, wskazuje na poczatek kolejki
    if(if_empty()) { // sprawdzamy czy nie jest pusta
    while (h->next)
    h=h->next; // szukamy konca
    h->next=v; // wstawiamy na koniec
    }
    else
    head=v;
}

template <typename E>
void Queue<E>::show_queue() const {
    SNode<E>* v = head;
    if(if_empty()) {
    std::cout<<"Elementy Kolejki: "<<std::endl;
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
    std::cout<<"Kolejka jest pusta!"<<std::endl;
    }
}

#endif
