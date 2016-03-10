#include <iostream>
#include <sys/time.h>

using namespace std;

// Algorytm powiększający tablicę poprzez zmianę rozmiaru o 1 podczas
// każdorazowego dodawania nowego elementu

class Arr {

private:
int *arr = NULL; // wskaźnik na miejsce w pamięci
int counter = 0; // licznik miejsca

public:
void add_num(int number); // dodaje liczbe do tablicy

Arr(int a);
~Arr();

};

Arr::Arr(int a) {
//konstruktor - tablice inicjujemy od razu iloscia miejsc
    arr = new int [a];

    for(int i=0; i<a; i++)
        arr[i]=0;

}

Arr::~Arr() {
// destruktor - zwalniamy pamiec
delete []arr;

}

void Arr::add_num(int number) {

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

long double get_ms_time() {
// licz czas w ms
    timeval tv;

    gettimeofday(&tv,NULL);

    return (static_cast<long double>(tv.tv_sec) * 1000UL) + (static_cast<long double>(tv.tv_usec) / 1000UL);

}

int main() {

    int numbers;
    Arr *array_1=new Arr(10);

    cout<<"Podaj, ile liczb wpisać do tablicy, program sprawdzi czas wykonania algorytmu n=n+1 dla podanej wartości:";
    cin>>numbers;

    long double start_time = get_ms_time();

    for(int i=0; i<numbers; i++)
    array_1->add_num(0);

    long double delta = get_ms_time() - start_time;


    cout<<"Czas wykonania dla algorytmu n=n+1 dla "<<numbers<<" liczb wynosi "<<delta<<"ms"<<endl;

    delete array_1;

    return 0;

}
