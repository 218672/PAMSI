#include "tree.hh"

RBTree::RBTree() {

sentinel = new Node();
sentinel->father = sentinel;
sentinel->left_son = sentinel;
sentinel->right_son = sentinel;
root = sentinel;
sentinel->color='b';

}

RBTree::~RBTree() {

release(root);

}

void RBTree::release(Node* n) {

    if(n!=sentinel) {
    release(n->left_son);
    release(n->right_son);
    delete n;
    }

}

void RBTree::rotate_left(Node* n) {

Node *a, *b;

a=n->right_son;

if(a!=sentinel) {
    b=n->father;
    n->right_son=a->left_son;

    if(n->right_son!=sentinel)
    n->right_son->father=n;

    a->left_son=n;
    a->father=b;
    n->father=a;

    if(b!=sentinel) {
        if(b->left_son==n)
        b->left_son=a;
        else
        b->right_son=a;
    }
    else
    root=a;
}

}

void RBTree::rotate_right(Node* n) {

Node *a, *b;

a=n->left_son;

if(a!=sentinel) {
    b=n->father;
    n->left_son=a->right_son;
    if(n->left_son!=sentinel)
    n->left_son->father=n;

    a->right_son=n;
    a->father=b;
    n->father=a;

    if(b!=sentinel) {
        if(b->left_son==n)
        b->left_son=a;
        else
        b->right_son=a;
    }
    else
    root=a;

}

}

void RBTree::add(const int& elem) {

Node *n, *a;

n = new Node();
n->left_son=sentinel;
n->right_son=sentinel;
n->father=root;
n->elem=elem;

if(n->father==sentinel) //gdy drzewo jest puste
root=n; // węzeł staje się korzeniem
else
while(true) { // szukanie odpowiedniego liścia do zastąpienia go nowym węzłem
    if(elem<(n->father->elem)) {
        if(n->father->left_son==sentinel) {
            n->father->left_son=n;
            break;
        }
        n->father=n->father->left_son;
    }
    else {
        if(n->father->right_son==sentinel) {
            n->father->right_son=n;
            break;
        }
        n->father=n->father->right_son;
    }
}

n->color='r'; // ustawiamy kolor nowo wstawionego węzła na czerwony

while((n!=root) && (n->father->color=='r')) {
    if(n->father==n->father->father->left_son) {
        a=n->father->father->right_son; // pokazujemy na wujka n

        if(a->color=='r') { // sytuacja nr jeden: ojciec wstawionego węzła jest czerwony, wujek też
            n->father->color='b';
            a->color='b';
            n->father->father->color='r';
            n=n->father->father;
            continue;
        }

        if(n==n->father->right_son) { // wujek czarny, a węzeł jest prawym synem ojca
          n=n->father;
          rotate_left(n);
        }

        n->father->color='b';
        n->father->father->color='r';
        rotate_right(n->father->father);
        break;
    }
    else { // przypadki lustrzane
        a=n->father->father->left_son;

        if(a->color=='r') {
            n->father->color='b';
            a->color='b';
            n->father->father->color='r';
            n=n->father->father;
            continue;
        }

        if(n==n->father->left_son) {
            n=n->father;
            rotate_right(n);
        }

        n->father->color='b';
        n->father->father->color='r';
        rotate_left(n->father->father);
        break;
    }

}

root->color='b';

}

int RBTree::find(const int& elem) {
    Node* tmp_n;
    tmp_n=root;
    while((tmp_n!=sentinel) && (tmp_n->elem!=elem))
        if(elem<tmp_n->elem)
        tmp_n=tmp_n->left_son;
        else
        tmp_n=tmp_n->right_son;
    if(tmp_n==sentinel)
    throw "Nie znaleziono elementu!";
    return tmp_n->elem;
}
