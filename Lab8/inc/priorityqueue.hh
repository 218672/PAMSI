#ifndef priorityqueue_hh
#define priorityqueue_hh
#include "ipriorityqueue.hh"

template <typename E>
class PQNode;
template <typename E>
class PriorityQueue;

 /*!
* \brief Klasa węzła kolejki.
*
* Zawiera element węzła oraz wskaźnik na następny węzeł.
*/
template <typename E>
class PQNode {

friend class PriorityQueue<E>; // przyznajemy dostep do wezla klasie Queue

private:
E elem; /*!< Element kolejki */
int value; /*!< Wartosc elementu */
PQNode<E>* next; /*!< Wskaźnik na kolejny węzeł */

};

 /*!
* \brief Klasa kolejki.
*
* Zawiera metody umożliwiające operacje na kolejce.
*/
template <typename E>
class PriorityQueue : public IPriorityQueue<E> {

private:
PQNode<E>* front; /*!< Wskaźnik na początek kolejki */
PQNode<E>* end; /*!< Wskaźnik na koniec kolejki */
int queue_size=0; /*!< Rozmiar kolejki */

public:
PriorityQueue() {
front = NULL; // inicjalizacja NULLami poczatku i konca
end = NULL;
};
~PriorityQueue() {};

/**
 * Funkcja dodająca element do kolejki
 *
 * \param[in] element typu E
 *
 */
void add(const E& elem, const int& value);

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
void PriorityQueue<E>::add(const E& elem, const int& value) {

    PQNode<E>* v = new PQNode<E>;
    PQNode<E>* tmp = new PQNode<E>;
	PQNode<E>* tmp_2 = new PQNode<E>;
    v->elem=elem;
    v->value=value;
    v->next=NULL;
    PQNode<E>* e = end;
    PQNode<E>* f = front;
    if(size()!=0) { // sprawdzamy czy nie jest pusta
    	while(f->next) {
		if(f->value>=value)
    	break;
		tmp_2=f;
    	f=f->next;
    	}
    	if(f->next!=NULL) {
		if(f!=front) {
		tmp_2->next=v;
    	tmp=f;
    	v->next=tmp;
    	queue_size++; // zwiekszamy rozmiar kolejki o 1
		}
		else {
		v->next=f;
		front=v;
		}
    	}
		else if(f->next==NULL && size()==1) {
			if(v->value>f->value) {
			f->next=v;
			end=v;
			queue_size++;
			}
			else {
			v->next=f;
			front=v;
			queue_size++;
			}
		}
    	else {
    	e->next=v;
    	end=v;
    	queue_size++; // zwiekszamy rozmiar kolejki o 1
    	}
    }
    else {
    front=v; // ustawiamy nowy poczatek i nowy koniec
    end=v;
    queue_size++; // zwiekszamy rozmiar kolejki o 1
    }
}

template <typename E>
E PriorityQueue<E>::remove() {
/* Wyrzuca wyjątek gdy kolejka jest pusta */
    if(size()!=0) {
        PQNode<E>* old=front;
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
int PriorityQueue<E>::size() {
    return queue_size;
}

template <typename E>
void PriorityQueue<E>::show_queue() {
    PQNode<E>* tmp = front;
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
