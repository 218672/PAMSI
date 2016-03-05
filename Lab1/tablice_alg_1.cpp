#include <iostream>
#include <time.h>

using namespace std;

// Algorytm powiększający tablicę poprzez zmianę rozmiaru o 1 podczas
// każdorazowego dodawania nowego elementu

class Arr {

private:
int *arr = new int [10];
int counter = 0;

public:
void add_num(int number);

};

void Arr::add_num(int number) {

    if (counter<10) {
        arr[counter]=number;
        counter++;
        }
    else  {
        int *new_a = new int [counter+1];
        for (int i=0; i<counter-1; i++) {
        new_a[i]=arr[i];
        }
        new_a[counter]=number;
        delete [] arr;
        arr = new int [counter+1];
        for (int i=0; i<counter-1; i++) {
        arr[i]=new_a[i];
        }
        delete [] new_a;
        counter++;
        cout<<"Powiekszono tablice o 1"<<endl;
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

    cout<<"Czas wykonania dla algorytmu n=n+1 dla "<<numbers<<" liczb wynosi "<<diff<<"ms"<<endl;

}
