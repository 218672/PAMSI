#include <iostream>
#include <sys/time.h>
#include "array1.hh"

using namespace std;


Arr_1::Arr_1(int a) {
//konstruktor - tablice inicjujemy od razu iloscia miejsc
    arr = new int [a];

    for(int i=0; i<a; i++)
        arr[i]=0;

}

Arr_1::~Arr_1() {
// destruktor - zwalniamy pamiec
delete []arr;

}

void Arr_1::add_num(int number) {

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
