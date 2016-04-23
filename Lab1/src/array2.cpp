#include <iostream>
#include <sys/time.h>
#include "array2.hh"

using namespace std;


Arr_2::Arr_2(int a) {
//konstruktor - tablice inicjujemy od razu iloscia miejsc
    arr = new int [a];

    for(int i=0; i<a; i++)
        arr[i]=0;

}

Arr_2::~Arr_2() {
// destruktor - zwalniamy pamiec
delete []arr;

}

void Arr_2::add_num(int number) {

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
