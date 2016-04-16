#ifndef queue1_hh
#define queue1_hh
#include "queue.hh"

template <typename E>
class Node;
template <typename E>
class Queue;

 /*!
* \brief Klasa węzła kolejki.
*
* Zawiera element węzła oraz wskaźnik na następny węzeł.
*/
template <typename E>
class Node {

friend class Queue<E>; // przyznajemy dostep do wezla klasie Queue

private:
E elem; /*!< Element kolejki */
Node<E>* next; /*!< Wskaźnik na kolejny węzeł */

};

 /*!
* \brief Klasa kolejki.
*
* Zawiera metody umożliwiające operacje na kolejce.
*/
template <typename E>
class Queue : public IQueue<E> {

private:
Node<E>* front; /*!< Wskaźnik na początek kolejki */
Node<E>* end; /*!< Wskaźnik na koniec kolejki */
int queue_size=0; /*!< Rozmiar kolejki */

public:
Queue() {
front = NULL; // inicjalizacja NULLami poczatku i konca
end = NULL;
};
~Queue() {};

/**
 * Funkcja dodająca element do kolejki
 *
 * \param[in] element typu E
 *
 */
void add(const E& elem);

/**
 * Funkcja usuwająca element z kolejki
 * Wyrzuca wyjątek EmptyQueueException jeśli kolejka jest pusta.
 *
 * \return Element typu E
 *
 */
E remove();

/**
 * Funkcja zwracająca rozmiar kolejki
 *
 * \return Rozmiar kolejki typu int
 *
 */
int size();

/**
 * Funkcja wyświetlająca kolejkę
 *
 *
 */
void show_queue(); // pokazuje kolejke

};

template <typename E>
void Queue<E>::add(const E& elem) {
    Node<E>* v = new Node<E>;
    v->elem=elem;
    v->next=NULL;
    Node<E>* e = end;
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

template <typename E>
E Queue<E>::remove() {
/* Wyrzuca wyjątek gdy kolejka jest pusta */
    if(size()!=0) {
        Node<E>* old=front;
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

template <typename E>
int Queue<E>::size() {
    return queue_size;
}

template <typename E>
void Queue<E>::show_queue() {
    Node<E>* tmp = front;
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

#endif
