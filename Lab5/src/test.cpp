#include <iostream>
#include <string>
#include "list.hh"
#include "hasharray.hh"
#include "asarray.hh"


int main() {

AsArray nowa(100);
std::string file_name="phonebook.txt";
int amount_of_data;

std::cout<<"Ile danych wpisać do książki telefonicznej? ";
std::cin>>amount_of_data;

nowa.read_from_file(file_name, amount_of_data);

return 0;
}
