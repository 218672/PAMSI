#include "graph.hh"


Graph::Graph(int vertices) {

size_of_neighbours_list = vertices;
neighbours_list = new List<int> [size_of_neighbours_list];

cost_matrix = new int* [size_of_neighbours_list];

for(int i=0; i<size_of_neighbours_list; i++) {

    cost_matrix[i] = new int [size_of_neighbours_list];

    for(int j=0; j<size_of_neighbours_list; j++)
    cost_matrix[i][j]=0;
}

}

Graph::~Graph() {

delete []neighbours_list;

for(int i=0; i<size_of_neighbours_list; i++)
delete []cost_matrix[i];

delete []cost_matrix;

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

void Graph::BBsearch(const int& v) {

    PriorityQueue<int>* vertices = new PriorityQueue<int>;
    PriorityQueue<int>* path_lengths = new PriorityQueue<int>;
    path_lengths->add(0,0);
    int number_of_extended_paths=0;
    int total_route=0;
    int minimal_route=0;

    vertices->add(0, cost_matrix[0][0]); // zaczynamy od węzła startowego

    while(vertices->size()!=0) { // zdejmujemy elementy z kolejki priorytetowej dopoki nie znajdziemy szukanego

        int elem=vertices->remove();
        total_route=path_lengths->remove();
        if(elem==v) {
        std::cout<<"Znaleziono element!"<<std::endl;
        minimal_route=total_route; // oznaczamy minimalna trase po znalezieniu elementu
        break;
        }



        for(int i=0; i<neighbours_list[elem].size(); i++) {
            int tmp_elem=neighbours_list[elem].at(i+1);
            number_of_extended_paths++; // zwiekszamy ilosc rozwinietych sciezek o 1
            vertices->add(tmp_elem, total_route+cost_matrix[elem][tmp_elem]); // dodajemy sasiada do kolejki
            path_lengths->add(total_route+cost_matrix[elem][tmp_elem],total_route+cost_matrix[elem][tmp_elem]); // dodajemy dlugosc drogi do kolejki
        }

    }

    while(vertices->size()!=0) { // szukamy alternatywnych drog biorac pod uwage reszte elementow w kolejce

        int tmp_elem=vertices->remove();
        total_route=path_lengths->remove();
        if(total_route>=minimal_route) { // jesli sciezka jest wieksza niz minimalna, pomijamy element
            continue;
        }
        else if(tmp_elem!=v && total_route<minimal_route) { // dodajemy sasiadow jezeli jest szansa na znalezienie krotszej sciezki
            for(int i=0; i<neighbours_list[tmp_elem].size(); i++) {
                int tmp_elem3=neighbours_list[tmp_elem].at(i+1);
                number_of_extended_paths++; // zwiekszamy ilosc rozwinietych sciezek o 1
                vertices->add(tmp_elem3, total_route+cost_matrix[tmp_elem][tmp_elem3]); // dodajemy sasiada do kolejki
                path_lengths->add(total_route+cost_matrix[tmp_elem][tmp_elem3],total_route+cost_matrix[tmp_elem][tmp_elem3]); // dodajemy dlugosc drogi do kolejki
            }
        }

        else if(tmp_elem==v && total_route<minimal_route) { // jak znalezlismy nowa krotsza sciezke to zapisujemy
        minimal_route=total_route;
        std::cout<<"Znaleziono nową minimalną ścieżkę!"<<std::endl;
        }

    }

    std::cout<<"Liczba rozwiniętych sciezek: "<<number_of_extended_paths<<std::endl;


    delete vertices;
    delete path_lengths;
}

void Graph::BBsearch_with_extended_list(const int& v) {

    PriorityQueue<int>* vertices = new PriorityQueue<int>;
    PriorityQueue<int>* path_lengths = new PriorityQueue<int>;
    visited = new int[size_of_neighbours_list];
    path_lengths->add(0,0);
    int number_of_extended_paths=0;
    int total_route=0;
    int minimal_route=0;

    for(int i=0; i<size_of_neighbours_list; i++)
    visited[i]=0;

    vertices->add(0, cost_matrix[0][0]); // zaczynamy od węzła startowego

    while(vertices->size()!=0) { // zdejmujemy elementy z kolejki priorytetowej dopoki nie znajdziemy szukanego

        int elem=vertices->remove();
        total_route=path_lengths->remove();

        if(visited[elem]==0)
        visited[elem]=1; // jesli odwiedzilismy wierzcholek, oznaczamy

        if(elem==v) {
        std::cout<<"Znaleziono element!"<<std::endl;
        minimal_route=total_route; // oznaczamy minimalna trase po znalezieniu elementu
        break;
        }



        for(int i=0; i<neighbours_list[elem].size(); i++) {
            int tmp_elem=neighbours_list[elem].at(i+1);
            if(visited[tmp_elem]==0) { // tylko jesli go jeszcze nie rozwinieto
            number_of_extended_paths++; // zwiekszamy ilosc rozwinietych sciezek o 1
            vertices->add(tmp_elem, total_route+cost_matrix[elem][tmp_elem]); // dodajemy sasiadow do kolejki
            path_lengths->add(total_route+cost_matrix[elem][tmp_elem],total_route+cost_matrix[elem][tmp_elem]); // dodajemy droge do kolejki
            }
        }

    }

   while(vertices->size()!=0) { // szukamy alternatywnych drog biorac pod uwage reszte elementow w kolejce

        int tmp_elem=vertices->remove();
        total_route=path_lengths->remove();

        if(visited[tmp_elem]==0)
        visited[tmp_elem]=1; // jesli odwiedzilismy wierzcholek, oznaczamy

        if(total_route>=minimal_route) {
            continue;
        }
        else if(tmp_elem!=v && total_route<minimal_route) {
            for(int i=0; i<neighbours_list[tmp_elem].size(); i++) {
                int tmp_elem3=neighbours_list[tmp_elem].at(i+1);
                if(visited[tmp_elem3]==0) { // tylko jesli go jeszcze nie rozwinieto
                number_of_extended_paths++; // zwiekszamy ilosc rozwinietych sciezek o 1
                vertices->add(tmp_elem3, total_route+cost_matrix[tmp_elem][tmp_elem3]); // dodajemy sasiadow do kolejki
                path_lengths->add(total_route+cost_matrix[tmp_elem][tmp_elem3],total_route+cost_matrix[tmp_elem][tmp_elem3]); // dodajemy droge do kolejki
                }
            }
        }

        else if(tmp_elem==v && total_route<minimal_route) { // jak znalezlismy nowa krotsza sciezke to zapisujemy
        minimal_route=total_route;
        std::cout<<"Znaleziono nową minimalną ścieżkę!"<<std::endl;
        }

    }

    std::cout<<"Liczba rozwiniętych sciezek: "<<number_of_extended_paths<<std::endl;


    delete vertices;
    delete path_lengths;
    delete visited;


}
