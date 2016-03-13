#ifndef kolejka_hh
#define kolejka_hh

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

// metody dostepu do danych
E get_element() {
return elem;
}

Node get_next() {
return next;
}

// metody modyfikujace
void set_element(E new_elem) {
elem=new_elem;
}

void set_next(Node<E> new_node) {
next=new_node;
}

};

template <typename E>
class Queue { // kolejka
public:
Queue() {
front=NULL;
end=NULL;
}; // konstruktor
~Queue() {}; // destruktor
bool if_empty() const; // sprawdza czy kolejka jest pusta
const E& on_front() const; // zwraca pierwszy element
void remove(); // usuwa element z poczatku
void add(const E& elem); // dodaje element na koniec
void show_queue() const; // pokazuje kolejke

private:
Node<E>* front; // początek kolejki
Node<E>* end; // koniec kolejki
};

template <typename E>
bool Queue<E>::if_empty() const {
Node<E>* v = front;
if (v!=NULL)
return true; // zwroc 1 jak nie pusta
else
return false; // zwroc 0 jak pusta
}

template <typename E>
void Queue<E>::remove() {
    if(if_empty()) {
        Node<E>* old=front; // wzkaznik na poczatek
        front=old->next; // zmieniamy poczatek kolejki
        delete old; // usuwamy pierwszy element
    }
    else
    std::cout<<"Kolejka jest pusta!"<<std::endl;
}

template <typename E>
void Queue<E>::add(const E& elem) {
    Node<E>* v = new Node<E>; // nowy wezel
    v->elem=elem; // wpisujemy pozadany element
    v->next=NULL; // wezel wskazuje na NULL
    Node<E>* e = end; // wezel pomocniczy, wskazuje na koniec kolejki
    if(if_empty()) { // sprawdzamy czy nie jest pusta
    e->next=v;
    end=v;
    }
    else {
    front=v;
    end=v;
    }
}

template <typename E>
void Queue<E>::show_queue() const {
    Node<E>* v = front;
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
