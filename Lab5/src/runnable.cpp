#include "runnable.hh"
#include <iostream>
#include <string>
#include "list.hh"
#include "hasharray.hh"
#include "asarray.hh"

void Runnable::run() {

AsArray *nowa = NULL;
std::string file_name="phonebook.txt";
int amount_of_data[]={10, 100, 1000, 10000, 100000};

for(int i=0; i<5; i++) {

nowa = new AsArray(10);

nowa->read_from_file(file_name, amount_of_data[i]);

nowa->search_with_file(file_name, amount_of_data[i]);

delete nowa;

}

}
