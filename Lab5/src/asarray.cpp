#include "hasharray.hh"
#include "list.hh"
#include "asarray.hh"
#include "timer.hh"
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

    (hasharr->arr[hasharr->hash(key)]).add(key, value, 1);

    if(hasharr->number_of_not_empty_lists==hasharr->size_of_arr) {
    hasharr->realloc_and_rehash();
    }
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

void AsArray::read_from_file(std::string file_name, int amount_of_data) {
    std::ifstream file;
    Timer *tim = new Timer();
    file.open(file_name, std::ios::in);

    if(!file.good())
    std::cout<<"Nie udało się otworzyć pliku!"<<std::endl;

    std::string name;
    int phone_number;

    tim->tim_start();
    for(int i=0; i<amount_of_data; i++) {
    file>>name>>phone_number;
    if(file.good())
    insert(name, phone_number);
    else {
    std::cout<<"Przerwa w zapisie!"<<std::endl;
    break;
    }
    }
    tim->tim_stop();
    std::cout<<"Zapis zakończono."<<std::endl;
    std::cout<<"Zapis do tablicy asocjacyjnej "<<amount_of_data<<" elementów trwał "<<tim->return_time()<<"ms."<<std::endl;

    delete tim;
}

void AsArray::search_with_file(std::string file_name, int amount_of_data) {
    std::ifstream file;
    Timer *tim = new Timer();
    file.open(file_name, std::ios::in);

    if(!file.good())
    std::cout<<"Nie udało się otworzyć pliku!"<<std::endl;

    std::string name;
    int phone_number;

    tim->tim_start();
    for(int i=0; i<amount_of_data; i++) {
    file>>name>>phone_number;
    if(file.good()) {
    try {
    phone_number=search(name);
    }
    catch (const char* SearchException) {
    std::cout<<SearchException<<std::endl;
    }
    }
    else {
    std::cout<<"Przerwa w odczycie!"<<std::endl;
    break;
    }
    }
    tim->tim_stop();
    std::cout<<"Odczyt zakończono."<<std::endl;
    std::cout<<"Odczyt z tablicy asocjacyjnej "<<amount_of_data<<" elementów trwał "<<tim->return_time()<<"ms."<<std::endl;

    delete tim;
}



