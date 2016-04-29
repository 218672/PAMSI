#ifndef graph_hh
#define graph_hh
#include "igraph.hh"
#include "list.hh"

class Graph : public IGraph {

private:
List<int>* neighbours_list=NULL;

public:
void add_vertex(const int& v);
void add_edge(const int& x, const int& y);
void remove_vertex(const int& v);
void remove_edge(const int& x, const int& y);
List get_neighbours(const int& v);
bool is_connected(const int& x, const int& y);
int search_path_BFS(const int& v);
int search_path_DFS(const int& v);
Graph();
~Graph();

};

#endif
