#include "lista_jednokierunkowa.hh"

template <typename E>
void SLinkedList<E>::add_front(const E& elem) {
SNode<E>* v = new SNode<E>;
v->elem=elem;
v->next=head;
head=v;
}

template <typename E>
void SLinkedList<E>::remove_front() {
    SNode<E>* old=head;
    head=old->next;
    delete old;
}
