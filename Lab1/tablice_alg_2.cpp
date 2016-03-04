#include <iostream>
#include <time.h>

using namespace std;

// Algorytm powiększający tablicę o połowę podczas
// każdorazowego dodania nowego elementu w przypadku pełnej tablicy

class Arr {
public:
int *arr = new int [10];
int counter = 0;
int second_counter=0;

void add_num(int number);

};

void Arr::add_num(int number) {

    if (counter<10+second_counter) {
        arr[counter]=number;
        counter++;
        }
    else  {
        int *new_a = new int [counter*2];
        for (int i=0; i<counter-1; i++) {
        new_a[i]=arr[i];
        }
        new_a[counter]=number;
        delete [] arr;
        arr = new int [counter*2];
        for (int i=0; i<counter-1; i++) {
        arr[i]=new_a[i];
        }
        delete [] new_a;
        counter++;
        second_counter=counter;
        cout<<"Powiekszono tablice o polowe"<<endl;
        }

}

int main() {

    int numbers;
    clock_t first, second;
    Arr array_1;

    cout<<"Podaj, ile liczb wpisać do tablicy, program sprawdzi czas wykonania algorytmu n=n+1 dla podanej wartości:";
    cin>>numbers;

    first = clock();

    for(int i=0; i<numbers; i++)
    array_1.add_num(1);

    second = clock();

    long diff=(long)(second-first);

    cout<<"Czas wykonania dla algorytmu n=2n dla "<<numbers<<" liczb wynosi "<<diff<<"ms"<<endl;
}
