#ifndef tree_hh
#define tree_hh
#include "itree.hh"
#include <cstddef>

class Node {
friend class RBTree;
private:
int elem;
char color;
Node* father;
Node* left_son;
Node* right_son;

};

class RBTree : public IRBTree {

private:
Node* root=NULL;
Node* sentinel=NULL;

public:
RBTree();
~RBTree();
void add(const int& elem);
int find(const int& elem);
void release(Node* n);
void rotate_left(Node* n);
void rotate_right(Node* n);

};

#endif
