#include "graph.hh"

Graph::Graph(int vertices) {

neighbours_list = new List<int> [vertices];

for(int i=0; i<vertices; i++)
add_vertex(i);

}

void Graph::add_vertex(const int& v) {

    neighbours_list[v].add(v, neighbours_list[v].size()+1);

}

void Graph::add_edge(const int& x, const int& y) {

    neighbours_list[x].add(y, neighbours_list[x].size()+1);
    neighbours_list[y].add(x, neighbours_list[y].size()+1);

}

void Graph::remove_vertex(const int& v) {

}

void Graph::remove_edge(const int& x, const int& y) {

}

List Graph::get_neighbours(const int& v) {
    return neighbours_list[v];
}

bool Graph::is_connected(const int& x, const int& y) {
    if(neighbours_list[i].if_exist(y)==true)
        return true;
    else
        return false;
}

int search_path_BFS(const int& v) {

}

int search_path_DFS(const int& v) {

}
