#include "tree.hh"

Tree::Tree() {

sentinel = new Node();
sentinel->father=NULL;
sentinel->left_son=NULL;
sentinel->right_son=NULL;

}

void Tree::add(int elem) {

    Node* son = new Node();
    son->left_son=sentinel;
    son->right_son=sentinel;
    son->father=root;
    son->elem=elem;

    if(son->father!=sentinel) {
    int flag;
    while(flag) {
        if(elem<(son->father->elem)) {
            if(son->father->left_son==sentinel) {
            son->father->left_son=son;
            son->color='r';
            flag=0;
            }
        }
        else if(son->father->right_son==sentinel) {
            son->father->right_son=son;
            flag=0;
        }
        else {
        son->father=son->father=right;
            flag=1;
        }
        }
    }
    else {
    root=son;
    son->color='r'
    }
}

int Tree::find(int elem) {

}
