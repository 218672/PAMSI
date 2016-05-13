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
        if(j==1)
        graph->add_edge(j, j*2, rand()%1000);
        else {
        graph->add_edge(j, j*2, rand()%1000);
        graph->add_edge(j, (j*2)-1, rand()%1000);
        }
    }

    for(int j=number_of_vertices[i]; j>3; j--)
        graph->add_edge(j, j-1, rand()%1000);

    delete graph;

}

delete tim;

}
