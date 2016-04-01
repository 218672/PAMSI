#ifndef stos_hh
#define stos_hh
#include "list.hh"

class Node;
class Stack;

class Node {
friend class Stack;

private:

int elem;
Node* next;

};

class Stack : public IList {

private:
Node* head; // góra stosu
int get(int at=0); // funkcja bezuzyteczna, nie uzywamy, at jako bezuzyteczny w stosie parametr jest ustawiany jako domyslny, nie wpisujemy go w wywolaniu

public:
Stack() {
head=NULL;
}

void add(int elem, int at=0); // to samo tutaj z parametrem at, nawet wywolany nie zrobi niczego
void remove(int at=0); // i tu tez
int size();
bool if_empty() const;


};

#endif
