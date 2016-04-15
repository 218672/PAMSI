#include "asarray.hh"

AsArray::AsArray(int number_of_elements) {
hasharr = new HashArray(number_of_elements);
}

~AsArray::AsArray() {
delete hasharr;
}

int& AsArray::operator[](const& std::string arg) {

}

