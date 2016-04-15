#include "ilist.hh"

void List::add(const std::string& elem, int i) {
/* Wyrzuca wyjatek jesli uzytkownik poda zly indeks */
    Node* v = new Node;
    Node* tmp = new Node;
    v->elem=elem;

    if(i>1 && i<size()+1 && size()!=0) { // jesli nie na pierwsze miejsce i nie dalej niz rozmiar+1, czyli gdzieś w środku
    Node* f = front;
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
    Node* e = end;
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

E List<E>::remove(int i) {
    if(i==1) {
    if(size()!=0) { // jesli nie jest pusta
        Node* old=front;
        front=old->next;
        list_size--; // zmniejszamy rozmiar listy o 1
        std::string temp=old->elem;
        delete old; // usuwamy pierwszy element
        return temp;
    }
    else {
    std::string EmptyListException = "Lista jest pusta!";
    throw EmptyListException; // wyrzuca wyjatek jesli pusta
    }
    }
    else if(i==size() && i>1) { // jesli usuwamy koncowy, a lista ma wiecej niz jeden element
    Node* v = front;
    Node* e = end;
    if(size()!=0) { // tylko jesli nie jest pusta
            while(v->next->next)
            v=v->next;
            v->next=NULL;
            end=v;
            list_size--;
            std::string temp= e->elem;
            delete e; // zwracamy i usuwamy ostatni
            return temp;
    }
    else {
    std::string EmptyListException = "Lista jest pusta!";
    throw EmptyListException; // wyrzuca wyjatek jesli lista jest pusta
    }
    }
    else if(i>1 && i<size()) { // jesli nie usuwamy poczatkowego i ostatniego, tylko jakis w srodku
    Node* f = front;
    if(size()!=0) { // tylko jesli nie jest pusta
            for(int j=1; j<(i-1); j++)
            f=f->next;
            Node* tmp = f->next;
            f->next=f->next->next; // przepinamy wskaźnik
            std::string temp = tmp->elem;
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

int List::size() {
    return list_size;
}

void List::show_list() {
    Node* tmp = front;
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
