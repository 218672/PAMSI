#include "hasharray.hh"
#include "list.hh"
#include "asarray.hh"
#include <string>
#include <iostream>

AsArray::AsArray(int number_of_elements) {
hasharr = new HashArray(number_of_elements);
}

AsArray::~AsArray() {
delete hasharr;
}

int AsArray::operator[](const std::string& key) {

}

void AsArray::insert(const std::string& key, const int& value) {
    (hasharr->arr[hasharr->hash(key)]).add(key, value, 1);
}

void AsArray::remove(const std::string& key) {
    int position=0;
    position=(hasharr->arr[hasharr->hash(key)]).find_key_position(key);

    if(position!=0) {
    (hasharr->arr[hasharr->hash(key)]).remove(position);
    std::cout<<"Usunięto element o podanym kluczu."<<std::endl;
    }
    else
    std::cout<<"Nie ma elementu o podanym kluczu."<<std::endl;

}

int AsArray::search(const std::string& key) {
    int searched_number=0;

        searched_number=(hasharr->arr[hasharr->hash(key)]).search_by_key(key);
        if(searched_number!=0)
        return searched_number;
        else
        throw "Nie ma takiego elementu!";
}



