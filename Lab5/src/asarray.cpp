#include "hasharray.hh"
#include "list.hh"
#include "asarray.hh"
#include <string>
#include <iostream>
#include <fstream>

AsArray::AsArray(int number_of_elements) {
hasharr = new HashArray(number_of_elements);
}

AsArray::~AsArray() {
delete hasharr;
}

int AsArray::operator[](const std::string& key) {
    int number = search(key);
    return number;
}

void AsArray::insert(const std::string& key, const int& value) {
    if(hasharr->arr[hasharr->hash(key)].size()==0)
    hasharr->number_of_not_empty_lists++;
    if(hasharr->number_of_not_empty_lists==hasharr->size_of_arr)
    hasharr->realloc_and_rehash();

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

bool AsArray::read_from_file(std::string file_name) {
    std::fstream file;
    file.open(file_name.c_str());
    if(!file.good())
return false;

    std::string name;
    int phone_number;

    while(true) {
    file>>name>>phone_number;
    if(file.good())
    insert(name, phone_number);
    else
    break;
    }
return true;
}



