#ifndef itree_hh
#define itree_hh
#include "tree.hh"

class Node;

class IRBTree {

public:
virtual void add(const int& elem)=0;
virtual int find(const int& elem)=0;
virtual void release(Node* n)=0;
virtual void rotate_left(Node* n)=0;
virtual void rotate_right(Node* n)=0;
virtual ~IRBTree() {}

};

#endif
