#ifndef tree_hh
#define tree_hh

class Node {
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
Tree();
~Tree();
void add(const int& elem);
int find(const int& elem);

};

#endif
