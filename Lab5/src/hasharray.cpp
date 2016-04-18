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
        h=(h << 4) + key[i];
        if ((g=(h & 0xF0000000)))
            h=h^(g | (g >> 24));
    }
    return h%size_of_arr;
}

void HashArray::realloc_and_rehash() {

        List *new_a = new List [size_of_arr*2];

        for (int i=0; i<size_of_arr; i++)
        new_a[i]=arr[i];

        delete [] arr;
        arr = new List [size_of_arr*2];

        for (int i=0; i<size_of_arr; i++)
        arr[i]=new_a[i];

        delete [] new_a;

        size_of_arr*=2;

}

