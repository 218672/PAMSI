#ifndef list1_hh
#define list1_hh
#include "list.hh"
#include "timer.hh"

template <typename E>
class Node;
template <typename E>
class List;

template <typename E>
class Node { // wezel listy
friend class List<E>; // przyznajemy dostep klasie List

private:
E elem; // element wezla
Node<E>* next; // wskaznik na nastepny element

};

template <typename E>
class List : public IList<E> {

private:
Node<E>* front; // wskaznik na poczatek listy
Node<E>* end; // wskaznik na koniec listy
int list_size=0;

public:
List() { // konstruktor
front = NULL; // inicjujemy NULLami poczatek i koniec
end = NULL;
};
~List() {}; // destruktor
void add(const E& elem, int i); // dodaje element na wybranym miejscu listy, wyrzuca wyjatek jesli nie ma takiego elementu
E remove(int i); // zdejmuje element z wybranego miejsca listy, wyrzuca wyjątek jeśli nie ma takiego elementu lub lista jest pusta
int size(); // zwraca rozmiar listy
void show_list(); // pokazuje elementy listy
void test_on(int numbers); // pomiaru czasu przeszukiwania, argumentem jest ilosc danych do wczytania

};

template <typename E>
void List<E>::add(const E& elem, int i) {
/* Wyrzuca wyjatek jesli uzytkownik poda zly indeks */
    Node<E>* v = new Node<E>; // nowy wezel pomocniczy, ktory chcemy wkleic do listy
    Node<E>* tmp = new Node<E>; // nowy wezel pomocniczy
    v->elem=elem; // wpisujemy pozadany element

    if(i>1 && i<size()+1 && size()!=0) { // jesli nie na pierwsze miejsce i nie dalej niz rozmiar+1, czyli nazwijmy to w środku
    Node<E>* f = front; // wezel pomocniczy, wskazuje na poczatek listy
    for(int j=1; j<(i-1); j++)
    f=f->next; // szukamy miejsca o jeden mniejszego
    tmp=f->next; // przypisujemy wezel pomocniczy do tego miejsca
    f->next=v; // wklejamy element pomiedzy dwa
    v->next=tmp;
    list_size++;
    }
    else if(i==1 && (size()==0)) { // jesli na pierwsze miejsce i lista jest pusta
    front=v; // inicjujemy poczatek i koniec listy
    end=v;
    list_size++;
    }
    else if(i==1 && (size()>0)) {
        v->next=front;
        front=v;
        list_size++;
    }
    else if(i==size()+1 && size()>0) { // jesli wklejamy na koniec i lista nie jest pusta
    Node<E>* e = end; // wezel pomocniczy, wskazuje na koniec listy
    if(size()!=0) { // sprawdzamy czy nie jest pusta
    e->next=v; // wklejamy na koniec
    v->next=NULL;
    end=v; // zmieniiamy koniec
    list_size++;
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
        Node<E>* old=front; // wzkaznik na poczatek
        front=old->next; // zmieniamy poczatek listy
        list_size--;
        E temp=old->elem;
        delete old; // usuwamy pierwszy element
        return temp; // zwracamy element
    }
    else {
    std::string EmptyListException = "Lista jest pusta!";
    throw EmptyListException; // wyrzuca wyjatek jesli pusta
    }
    }
    else if(i==size() && i>1) { // jesli usuwamy koncowy, a lista ma wiecej niz jeden element
    Node<E>* v = front; // nowy wezel pokacujacy na poczatek
    Node<E>* e = end; // nowy wezek wskazujacy na koniec
    if(size()!=0) { // tylko jesli nie jest pusta
            while(v->next->next)
            v=v->next; // szukamy przedostatniego
            v->next=NULL; // oznaczamy nowy koniec
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
    Node<E>* f = front; // nowy wezel pokacujacy na poczatek
    if(size()!=0) { // tylko jesli nie jest pusta
            for(int j=1; j<(i-1); j++)
            f=f->next;
            Node<E>* tmp = f->next; // przypisujemy go do tymczasowego
            f->next=f->next->next; // przepinamy wskaźnik
            E temp = tmp->elem;
            list_size--;
            delete tmp; // usuwamy element
            return temp; // zwracamy element
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
    Node<E>* tmp = front; // wskaznik na poczatek
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

Timer* tim = new Timer(); // stoper
Node<E>* tmp = front; // wskaznik na poczatek
tim->tim_start(); // mierzymy czas
while(tmp->next) { // przechodzimy wszystkie wezly
if(tmp->elem>0) {
// albo sobie zwracamy, albo wypisujemy, albo co kto lubi
}
else
tmp=tmp->next; // jesli to nie ten co chcemy to idziemy dalej, zlozonosc O(1) jednego przejscia, a O(n) calej operacji przeszukania
}
tim->tim_stop(); // koniec pomiaru czasu

std::cout<<"Przeszukanie listy "<<numbers<<" elementów trwa "<<tim->return_time()<<"ms"<<std::endl;

delete tim;

for(int i=0; i<numbers; i++)
remove(1); // kasujemy elementy z poczatku listy, zlozonosc O(1) jednej operacji, czyli O(n) calej

}

#endif
