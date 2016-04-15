#include "asarray.hh"

AsArray::AsArray(int size_of_arr) {
arr = new List [size_of_arr];

for(int i=0; i<size_of_arr; i++) {
List help_list = new List ();
arr[i]=help_list;
}

}

~AsArray::AsArray() {
delete arr;
}

bool AsArray::is_empty() {

if(size_of_arr==0)
    return true;
else
    return false;

}

void AsArray::insert(std::string name, int hashed_index) {
List *help_list = new List();
help_list=arr[hashed_index];
help_list->add(name, 1);
}
