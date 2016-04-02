#include <iostream>
#include "algorytmy.hh"
#include "struktura.hh"

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

long double Timer::get_ms_time() {

    timeval tv;

    gettimeofday(&tv,NULL);

    return (static_cast<long double>(tv.tv_sec)*1000UL) + (static_cast<long double>(tv.tv_usec)/1000UL);

}

void Timer::tim_start() {

time_of_start=get_ms_time();

}

void Timer::tim_stop() {

time_of_stop=get_ms_time();

}

long double Timer::return_time() {

return time_of_stop-time_of_start;

}
