#include "test.hh"
#include "graph.hh"
#include "timer.hh"
#include <cstdlib>
#include <iostream>

void Test::run(int Argc, char* Argv[]) {

srand(time(NULL));
Graph* graph = NULL;
Timer* tim = new Timer();
int number_of_vertices[4]={10,100,1000,10000};

for(int i=0; i<4; i++) {

    graph = new Graph(number_of_vertices[i]);

    for(int j=1; j<=(number_of_vertices[i]/2); j++) {
        if(j==1)
        graph->add_edge(j, j*2, rand());
        else {
        graph->add_edge(j, j*2, rand());
        graph->add_edge(j, (j*2)-1, rand());
        }
    }

    for(int j=number_of_vertices[i]; j>3; j--)
        graph->add_edge(j, j-1, rand());


    tim->tim_start();
    graph->BBsearch(number_of_vertices[i]/2);
    tim->tim_stop();

    std::cout<<"Czas wyszukania B&B  optymalnej drogi pierwszy-srodkowy dla grafu "<<number_of_vertices[i]<<" elementowego wynosi: "<<tim->return_time()<<"ms."<<std::endl<<std::endl;

    tim->tim_start();
    graph->BBsearch_with_extended_list(number_of_vertices[i]/2);
    tim->tim_stop();

    std::cout<<"Czas wyszukania B&B with extended list optymalnej drogi pierwszy-srodkowy dla grafu "<<number_of_vertices[i]<<" elementowego wynosi: "<<tim->return_time()<<"ms."<<std::endl<<std::endl;

    delete graph;

}

delete tim;

}
