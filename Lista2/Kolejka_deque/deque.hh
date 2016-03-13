#ifndef deque_hh
#define deque_hh

template <typename E>
class Node;
template <typename E>
class Deque;

template <typename E>
class Node {
friend class Deque<E>;

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
class Deque { // kolejka z dwoma koncami

public:
Deque() { // konstruktor
front=NULL;
end=NULL;
}
~Deque() {} // destruktor
int size() const; // zwraca rozmiar kolejki
bool if_empty() const; // zwraca true, jesli nie jest pusta
const E& on_front(); // zwraca pierwszy element
void add_front(const E& elem); // dodaje na początku kolejki
void add_back(const E& elem); // dodaje na koncu kolejki
void remove_front(); // usuwa z poczatku kolejki
void remove_back(); // usuwa z konca kolejki
void show_deque() const; // pokazuje kolejke

private:
Node<E>* front;
Node<E>* end;
};

template <typename E>
bool Deque<E>::if_empty() const {
Node<E>* v = front;
if (v!=NULL)
return true; // zwroc 1 jak nie pusta
else
return false; // zwroc 0 jak pusta
}

template <typename E>
void Deque<E>::add_front(const E& elem) {
    Node<E>* v = new Node<E>; // nowy wezel
    if(if_empty()) {
    v->elem=elem; // wpisujemy pozadany element
    v->next=front; // wskaznik na poczatek kolejki
    front=v; // oznaczamy nowy poczatek kolejki
    }
    else {
    v->elem=elem; // wpisujemy pozadany element
    v->next=front; // wskaznik na poczatek kolejki
    front=v; // oznaczamy nowy poczatek kolejki
    end=v; // oznaczamy nowy koniec kolejki
    }
}

template <typename E>
void Deque<E>::remove_front() {
    if(if_empty()) {
        Node<E>* old=front; // wzkaznik na poczatek
        front=old->next; // zmieniamy poczatek listy
        delete old; // usuwamy pierwszy element
    }
    else
    std::cout<<"Kolejka jest pusta!"<<std::endl;
}

template <typename E>
void Deque<E>::add_back(const E& elem) {
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
void Deque<E>::remove_back() {
    Node<E>* v = front; // nowy wezel pokacujacy na poczatek
    Node<E>* e = end;
    if(if_empty()) { // tylko jesli nie jest pusta
        if(v->next) { // jak mamy cos oprocz startowego
            delete e;
            while(v->next->next)
            v=v->next; // szukamy przedostatniego
            v->next=NULL; // oznaczamy nowy koniec
            end=v;
        }
        else { // jesli jest tylko startowy
        delete v; // kasujemy startowy
        front=NULL; // lista staje sie pusta
        }
    }
    else
    std::cout<<"Kolejka jest pusta!"<<std::endl;
}

template <typename E>
void Deque<E>::show_deque() const {
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
