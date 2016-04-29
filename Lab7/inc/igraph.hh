#ifndef igraph_hh
#define igraph_hh
#include "list.hh"

class IGraph {

public:
virtual void add_vertex(const int& v)=0;
virtual void add_edge(const int& x, const int& y)=0;
virtual void remove_vertex(const int& v)=0;
virtual void remove_edge(const int& x, const int& y)=0;
virtual List get_neighbours(const int& v)=0;
bool is_connected(const int& x, const int& y)=0;
virtual ~IGraph() {}

};

#endif
