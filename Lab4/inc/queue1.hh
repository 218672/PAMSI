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
Queue(int new_size) { // konstruktor
front = NULL; // inicjalizacja NULLami poczatku i konca
end = NULL;
queue_size=new_size;
};
~Queue() {}; // destruktor

/**
 * Funkcja dodająca element na początek kolejki
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
 * Funkcja zwracająca rozmiar kolejki.
 *
 * \return Rozmiar kolejki typu int
 *
 */
int size();

/**
 * Funkcja wyświetlająca kolejke
 *
 *
 */
void show_queue();

};

template <typename E>
void Queue<E>::add(const E& elem) {
    Node<E>* v = new Node<E>; // nowy wezel
    v->elem=elem; // wpisujemy pozadany element
    v->next=NULL; // wezel wskazuje na NULL
    Node<E>* e = end; // wezel pomocniczy, wskazuje na koniec kolejki
    if(size()!=0) { // sprawdzamy czy nie jest pusta
    e->next=v; // dodajemy wezel
    end=v; // zmieniamy koniec
    queue_size++;
    }
    else { // jesli nie pusta
    front=v; // ustawiamy nowy poczatek i nowy koniec
    end=v;
    queue_size++;
    }
}

template <typename E>
E Queue<E>::remove() {
/* Wyrzuca wyjątek gdy kolejka jest pusta */
    if(size()!=0) {
        Node<E>* old=front; // wzkaznik na poczatek
        front=old->next; // zmieniamy poczatek kolejki
        queue_size--;
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
    return queue_size;
}

template <typename E>
void Queue<E>::show_queue() {
    Node<E>* tmp = front; // wskaznik na koniec
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
