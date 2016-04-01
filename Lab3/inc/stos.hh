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

public:
Stack() {
head=NULL;
}

void add(int elem, int at);
void remove(int at);
int size();
bool if_empty() const;
int get(int i);

};

#endif
