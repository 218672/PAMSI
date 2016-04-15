#include "hasharray.hh"

HashArray::HashArray(int size_of_arr) {
arr = new List [size_of_arr];

for(int i=0; i<size_of_arr; i++) {
List help_list = new List ();
arr[i]=help_list;
}

~HashArray::HashArray() {
delete arr;
}

void HashArray::add(std::string name, int hashed_index) {
List *help_list = new List();
help_list=arr[hashed_index];
help_list->add(name, 1);
}

int HashArray::remove(std::string name, int hashed_index) {

}

int HashArray::hash(std::string name) {

}

