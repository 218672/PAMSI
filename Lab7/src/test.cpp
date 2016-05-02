#include "test.hh"
#include "graph.hh"
#include "timer.hh"
#include <cstdlib>
#include <iostream>

void Test::run(int Argc, char* Argv[]) {

Graph* graph = NULL;
Timer* tim = new Timer();
int number_of_vertices[6]={10,100,1000,10000,100000,1000000};

for(int i=0; i<6; i++) {

    graph = new Graph(number_of_vertices[i]);

    for(int j=1; j<=(number_of_vertices[i]/2); j++) {
        graph->add_edge(j, j*2);
        graph->add_edge(j, (j*2)-1);
    }

    tim->tim_start();
    graph->search_path_DFS(number_of_vertices[i]+1);
    tim->tim_stop();
    std::cout<<"Czas przeszukania wgłąb grafu "<<number_of_vertices[i]<<" elementowego wynosi "<<tim->return_time()<<"ms."<<std::endl<<std::endl;

    tim->tim_start();
    graph->search_path_BFS(number_of_vertices[i]+1);
    tim->tim_stop();
    std::cout<<"Czas przeszukania wszerz grafu "<<number_of_vertices[i]<<" elementowego wynosi "<<tim->return_time()<<"ms."<<std::endl<<std::endl;

    delete graph;

}

delete tim;

}
