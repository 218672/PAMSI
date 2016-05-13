#include "graph.hh"

Graph::Graph(int vertices) {

size_of_neighbours_list = vertices;
neighbours_list = new List<int> [vertices];

cost_matrix = new int * [size_of_neighbours_list];

for(int i=0; i<size_of_neighbours_list; i++) {

    cost_matrix[i] = new int [size_of_neighbours_list];

    for(int j=0; j<size_of_neighbours_list; j++)
    cost_matrix[i][j]=0;
}

}

Graph::~Graph() {

delete []neighbours_list;

}

void Graph::add_vertex(const int& v) {

    if(v<=size_of_neighbours_list)
    std::cout<<"Istnieje już węzeł o podanym numerze. Aktualnie graf zawiera "<<size_of_neighbours_list<<" wierzchołków."<<std::endl;

    List<int>* help = new List<int> [size_of_neighbours_list+1];

    for(int i=0; i<size_of_neighbours_list; i++)
    help[i]=neighbours_list[i];

    delete neighbours_list;

    size_of_neighbours_list++;

    neighbours_list = new List<int> [size_of_neighbours_list];

    for(int i=0; i<size_of_neighbours_list; i++)
    neighbours_list[i]=help[i];

    delete help;

}

void Graph::add_edge(const int& x, const int& y, const int& cost) {

    neighbours_list[x-1].add(y-1, neighbours_list[x-1].size()+1);
    neighbours_list[y-1].add(x-1, neighbours_list[y-1].size()+1);

    cost_matrix[x-1][y-1]=cost;

}

void Graph::remove_vertex(const int& v) {

    // metoda zostanie dodana gdy wierzchołki będą zawierać wartości

}

void Graph::remove_edge(const int& x, const int& y) {

    // metoda zostanie dodana gdy wierzchołki będą zawierać wartości

}

List<int> Graph::get_neighbours(const int& v) {
    return neighbours_list[v];
}

bool Graph::is_connected(const int& x, const int& y) {

    for(int i=0; i<neighbours_list[i].size(); i++)
        if(neighbours_list[i].at(i)==y)
            return true;

    return false;
}

void Graph::search_path_BFS(const int& v) {

    visited = new int[size_of_neighbours_list];

    for(int i=0; i<size_of_neighbours_list; i++)
    visited[i]=0;

    Queue<int>* tmp_q = new Queue<int>;

    for(int i=0; i<size_of_neighbours_list; i++) {
        if(visited[i]==0) {
            visited[i]=1;
            tmp_q->add(i);
            while(tmp_q->size()!=0) {
                int elem=tmp_q->remove();
                if(elem==v)
                std::cout<<"Znaleziono!"<<std::endl;
                for(int j=0; j<neighbours_list[elem].size(); j++) {
                    int tmp_elem=neighbours_list[elem].at(j+1);
                    if(visited[tmp_elem]==0) {
                        visited[tmp_elem]=1;
                        tmp_q->add(tmp_elem);
                    }
                }
            }
        }
    }

delete tmp_q;
delete visited;

}

void Graph::visit_DFS(int i, const int& v) {

        visited[i]=1;

        for(int j=0; j<neighbours_list[i].size(); j++) {
            int tmp_elem=neighbours_list[i].at(j);
            if(visited[tmp_elem]==0) {
            if(tmp_elem==v)
            std::cout<<"Znaleziono!"<<std::endl;
            visit_DFS(tmp_elem, v);
            }
        }
}

void Graph::search_path_DFS(const int& v) {

    visited = new int [size_of_neighbours_list];

    for(int i=0; i<size_of_neighbours_list; i++)
    visited[i]=0;

    for(int i=0; i<size_of_neighbours_list; i++)
        if(visited[i]==0)
            visit_DFS(i,v);

    delete visited;

}

int Graph::BBsearch(const int& v) {

}

int Graph::BBsearch_with_extended_list(const int& v) {

}
