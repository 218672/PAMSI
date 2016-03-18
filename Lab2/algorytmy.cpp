#include <iostream>
#include "struktura.hh"

class Arr_first_type: public DataStructure {

private:
int *arr = NULL; // wskaźnik na miejsce w pamięci
int counter = 0; // licznik miejsca

public:
void add_num(int number); // dodaje liczbe do tablicy
void init_by_zeros();

Arr_first_type(int a);
~Arr_first_type();

};

Arr_first_type::Arr_first_type(int a) {
//konstruktor - tablice inicjujemy od razu iloscia miejsc
    arr = new int [a];

    for(int i=0; i<a; i++)
        arr[i]=0;

}

Arr_first_type::~Arr_first_type() {
// destruktor - zwalniamy pamiec
delete []arr;

}

void Arr_first_type::add_num(int number) {

    if (counter<10) { // jesli niepelna to zapelniaj
        arr[counter]=number;
        counter++;
        }
    else  { // jesli pelna zrob nowa pomocnicza o wiekszym rozmiarze,
    // skopiuj stara, uwolnij pamiec ze starej, skopiuj do nowej, uwolnij pamięć z pomocniczej
        int *new_a = new int [counter+1];
        for (int i=0; i<counter-1; i++) {
        new_a[i]=arr[i];
        }
        new_a[counter]=number;
        delete[] arr;
        arr = new int [counter+1];
        for (int i=0; i<counter; i++) {
        arr[i]=new_a[i];
        }
        delete [] new_a;
        counter++;
        }

}

void Arr_first_type::init_by_zeros() {
    int zeros;
    std::cout<<"Ile wpisać zer?"<<std::endl;
    std::cin>>zeros;
    for(int i=0; i<zeros; i++)
    arr[i]=0;
}


class Arr_second_type: public DataStructure {

private:
int *arr = NULL; // wskaźnik na miejsce w pamięci
int counter = 0; // licznik miejsca
int second_counter=0; // licznik pomocniczy

public:
void add_num(int number); // dodaje liczbe do tablicy
void init_by_zeros();

Arr_second_type(int a);
~Arr_second_type();

};

Arr_second_type::Arr_second_type(int a) {
//konstruktor - tablice inicjujemy od razu iloscia miejsc
    arr = new int [a];

    for(int i=0; i<a; i++)
        arr[i]=0;

}

Arr_second_type::~Arr_second_type() {
// destruktor - zwalniamy pamiec
delete []arr;

}

void Arr_second_type::add_num(int number) {

    if (counter<10+second_counter) { // jesli niepelna to zapelniaj
        arr[counter]=number;
        counter++;
        }
    else  { // jesli pelna zrob nowa pomocnicza o wiekszym rozmiarze,
    // skopiuj stara, uwolnij pamiec ze starej, skopiuj do nowej, uwolnij pamięć z pomocniczej
        int *new_a = new int [counter*2];
        for (int i=0; i<counter-1; i++) {
        new_a[i]=arr[i];
        }
        new_a[counter]=number;
        delete [] arr;
        arr = new int [counter*2];
        for (int i=0; i<counter; i++) {
        arr[i]=new_a[i];
        }
        delete [] new_a;
        second_counter=second_counter+counter;
        counter++;
        }
}

void Arr_second_type::init_by_zeros() {
    int zeros;
    std::cout<<"Ile wpisać zer?"<<std::endl;
    std::cin>>zeros;
    for(int i=0; i<zeros; i++)
    arr[i]=0;
}

class Arr_third_type: public DataStructure {

private:
int *arr = NULL; // wskaźnik na miejsce w pamięci
int counter = 0; // licznik miejsca
int second_counter=0; // licznik pomocniczy

public:
void add_num(int number); // dodaje liczbe do tablicy
void init_by_zeros();

Arr_third_type(int a);
~Arr_third_type();


};

Arr_third_type::Arr_third_type(int a) {
//konstruktor - tablice inicjujemy od razu iloscia miejsc
    arr = new int [a];

    for(int i=0; i<a; i++)
        arr[i]=0;

}

Arr_third_type::~Arr_third_type() {
// destruktor - zwalniamy pamiec
delete []arr;

}

void Arr_third_type::add_num(int number) {

    if (counter<10+second_counter) { // jesli niepelna to zapelniaj
        arr[counter]=number;
        counter++;
        }
    else  { // jesli pelna zrob nowa pomocnicza o wiekszym rozmiarze,
    // skopiuj stara, uwolnij pamiec ze starej, skopiuj do nowej, uwolnij pamięć z pomocniczej
        int *new_a = new int [counter+100];
        for (int i=0; i<counter-1; i++) {
        new_a[i]=arr[i];
        }
        new_a[counter]=number;
        delete [] arr;
        arr = new int [counter+100];
        for (int i=0; i<counter; i++) {
        arr[i]=new_a[i];
        }
        delete [] new_a;
        counter++;
        second_counter=second_counter+100;
        }

}

void Arr_third_type::init_by_zeros() {
    int zeros;
    std::cout<<"Ile wpisać zer?"<<std::endl;
    std::cin>>zeros;
    for(int i=0; i<zeros; i++)
    arr[i]=0;
}


int main(){

}
