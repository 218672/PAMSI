#ifndef list_hh
#define list_hh
#include "list.hh"
#include "timer.hh"
#include <cstddef>
#include <cstring>
#include <iostream>

template <typename E>
class Node;
template <typename E>
class List;

 /*!
* \brief Klasa węzła listy.
*
* Zawiera element węzła oraz wskaźnik na następny węzeł.
*/
template <typename E>
class Node {

friend class List<E>; // przyznajemy dostep klasie List

private:
E elem; /*!< Element listy */
Node<E>* next; /*!< Wskaźnik na kolejny węzeł */

};


 /*!
* \brief Klasa listy.
*
* Zawiera metody umożliwiające operacje na liście.
*/
template <typename E>
class List : public IList<E> {

private:
Node<E>* front; /*!< Wskaźnik na początek listy */
Node<E>* end; /*!< Wskaźnik na koniec listy */
int list_size=0;  /*!< Rozmiar listy */

public:
List() {
front = NULL; // inicjujemy NULLami poczatek i koniec
end = NULL;
};
~List() {};

/**
 * Funkcja dodająca element do listy
 *
 * \param[in] element typu E
 * \param[in] pozycja i
 *
 */
void add(const E& elem, int i);

/**
 * Funkcja usuwająca element z listy
 * Wyrzuca wyjątek EmptyListException jeśli lista jest pusta oraz WrongIndexException jeśli wybrano zły indeks.
 *
 * \return Element typu E
 *
 */
E remove(int i);

/**
 * Funkcja zwracająca rozmiar listy
 *
 * \return Rozmiar kolejki typu int
 *
 */
int size();

/**
 * Funkcja wyświetlająca listę
 *
 *
 */
void show_list();

/**
 * Funkcja testująca kolejkę
 *
 *\param[in] liczba elementów do wpisania
 *
 */
void test_on(int numbers); // pomiaru czasu przeszukiwania, argumentem jest ilosc danych do wczytania

};

template <typename E>
void List<E>::add(const E& elem, int i) {
/* Wyrzuca wyjatek jesli uzytkownik poda zly indeks */
    Node<E>* v = new Node<E>;
    Node<E>* tmp = new Node<E>;
    v->elem=elem;

    if(i>1 && i<size()+1 && size()!=0) { // jesli nie na pierwsze miejsce i nie dalej niz rozmiar+1, czyli gdzieś w środku
    Node<E>* f = front;
    for(int j=1; j<(i-1); j++)
    f=f->next; // szukamy wezla poprzedzajacego
    tmp=f->next;
    f->next=v; // wklejamy element pomiedzy dwa wezly
    v->next=tmp;
    list_size++;
    }
    else if(i==1 && (size()==0)) { // jesli na pierwsze miejsce i lista jest pusta
    front=v;
    end=v;
    list_size++; // zwiekszamy rozmiar listy o 1
    }
    else if(i==1 && (size()>0)) { // jesli na pierwsze miejsce i lista nie jest pusta
        v->next=front;
        front=v;
        list_size++; // zwiekszamy rozmiar listy o 1
    }
    else if(i==size()+1 && size()>0) { // jesli wklejamy na koniec i lista nie jest pusta
    Node<E>* e = end;
    if(size()!=0) { // sprawdzamy czy nie jest pusta
    e->next=v; // wklejamy na koniec
    v->next=NULL;
    end=v;
    list_size++; // zwiekszamy rozmiar listy o 1
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
    if(size()!=0) { // jesli nie jest pusta
        Node<E>* old=front;
        front=old->next;
        list_size--; // zmniejszamy rozmiar listy o 1
        E temp=old->elem;
        delete old; // usuwamy pierwszy element
        return temp;
    }
    else {
    std::string EmptyListException = "Lista jest pusta!";
    throw EmptyListException; // wyrzuca wyjatek jesli pusta
    }
    }
    else if(i==size() && i>1) { // jesli usuwamy koncowy, a lista ma wiecej niz jeden element
    Node<E>* v = front;
    Node<E>* e = end;
    if(size()!=0) { // tylko jesli nie jest pusta
            while(v->next->next)
            v=v->next;
            v->next=NULL;
            end=v;
            list_size--;
            E temp= e->elem;
            delete e; // zwracamy i usuwamy ostatni
            return temp;
    }
    else {
    std::string EmptyListException = "Lista jest pusta!";
    throw EmptyListException; // wyrzuca wyjatek jesli lista jest pusta
    }
    }
    else if(i>1 && i<size()) { // jesli nie usuwamy poczatkowego i ostatniego, tylko jakis w srodku
    Node<E>* f = front;
    if(size()!=0) { // tylko jesli nie jest pusta
            for(int j=1; j<(i-1); j++)
            f=f->next;
            Node<E>* tmp = f->next;
            f->next=f->next->next; // przepinamy wskaźnik
            E temp = tmp->elem;
            list_size--;
            delete tmp; // usuwamy element i zwracamy
            return temp;
    }
    else {
    std::string EmptyListException = "Lista jest pusta!";
    throw EmptyListException; // wyrzuca wyjatek jesli jest pusta
    }
    }
    else {
    std::string WrongListIndexException = "Lista nie ma takiego pola, pamietaj o numeracji!";
    throw WrongListIndexException; // wyrzuca wyjatek jesli zly indeks
    }
}

template <typename E>
int List<E>::size() {
    return list_size;
}

template <typename E>
void List<E>::show_list() {
    Node<E>* tmp = front;
    if(size()!=0) { // jesli nie jest pusta
    std::cout<<"Elementy listy:"<<std::endl;
    std::cout<<tmp->elem<<std::endl; // wypisujemy pierwszy
        while(tmp->next) { // jesli cos procz pierwszego to tez wypisujemy
        tmp=tmp->next;
        std::cout<<tmp->elem<<std::endl;
        }
    }
    else
        std::cout<<"Lista jest pusta!"<<std::endl;
}

template <typename E>
void List<E>::test_on(int numbers) {
if(size()!=0) // jesli nie jest pusta to czyścimy
for(int i=0; i<=size(); i++)
remove(1);

for(int i=1; i<=numbers; i++)
add(0,1); // dodajemy dana ilosc zer, zlozonosc O(1) kazdej operacji, czyli O(n) calego zapelnienia

Timer* tim = new Timer();
Node<E>* tmp = front;
tim->tim_start();
while(tmp->next) { // przechodzimy wszystkie wezly
if(tmp->elem>0) {
// albo sobie zwracamy, albo wypisujemy, albo co kto lubi
}
else
tmp=tmp->next; // jesli to nie ten co chcemy to idziemy dalej, zlozonosc O(1) jednego przejscia, a O(n) calej operacji przeszukania
}
tim->tim_stop();

std::cout<<"Przeszukanie listy "<<numbers<<" elementów trwa "<<tim->return_time()<<"ms"<<std::endl;

delete tim;

for(int i=0; i<numbers; i++)
remove(1); // kasujemy elementy z poczatku listy, zlozonosc O(1) jednej operacji, czyli O(n) calej

}

#endif
