#ifndef list_hh
#define list_hh
#include "ilist.hh"

class Node;
class List;

class Node { // wezel listy
friend class List; // przyznajemy dostep klasie List

private:
std::string elem; // element wezla
Node* next; // wskaznik na nastepny element

};

class List : public IList {

private:
Node* front; // wskaznik na poczatek listy
Node* end; // wskaznik na koniec listy
int list_size=0;

public:
List() {
front = NULL; // inicjujemy NULLami poczatek i koniec
end = NULL;
};
~List() {};
void add(const std::string& elem, int i); // dodaje element na wybranym miejscu listy, wyrzuca wyjatek jesli nie ma takiego elementu
E remove(int i); // zdejmuje element z wybranego miejsca listy, wyrzuca wyjątek jeśli nie ma takiego elementu lub lista jest pusta
int size(); // zwraca rozmiar listy
void show_list(); // pokazuje elementy listy

};
