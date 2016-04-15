#include "hasharray.hh"

HashArray::HashArray(int number_of_elements) {
asarr = new AsArray(number_of_elements);
}

~HashArray::HashArray() {
delete asarr;
}

void int HashArray::insert_in_asarr(std::string name, int hashed_index) {
asarr->insert(name, hashed_index);
}

int HashArray::hash(std::string name) {

}

int HashArray::operator[](std::string arg) {
hash(arg);
}
