#include "hasharray.hh"
#include "asarray.hh"
#include "list.hh"
#include <string>

HashArray::HashArray(int size_of_arr) {
arr = new List [size_of_arr];
this->size_of_arr=size_of_arr;
}


HashArray::~HashArray() {
delete []arr;
}

int HashArray::hash(std::string key) {
    int g,h=0;

    for (int i=0; i<3; i++) {
        h=(h << 4) + key[1];
        if ((g=(h & 0xF0000000)))
            h=h^(g | (g >> 24));
    }
    return h % size_of_arr;
}

