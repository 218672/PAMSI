#include <iostream>
#include <sys/time.h>

using namespace std;

// Algorytm powiększający tablicę o 100 podczas
// każdorazowego dodania nowego elementu w przypadku pełnej tablicy

class Arr {

private:
int *arr = NULL;
int counter = 0;
int second_counter=0;

public:
void add_num(int number);

Arr(int a) {

    arr = new int [a];

    for(int i=0; i<a; i++)
        arr[i]=0;

}

};

void Arr::add_num(int number) {

    if (counter<10+second_counter) {
        arr[counter]=number;
        counter++;
        }
    else  {
        int *new_a = new int [counter+100];
        for (int i=0; i<counter-1; i++) {
        new_a[i]=arr[i];
        }
        new_a[counter]=number;
        delete [] arr;
        arr = new int [counter+100];
        for (int i=0; i<counter-1; i++) {
        arr[i]=new_a[i];
        }
        delete [] new_a;
        counter++;
        second_counter=second_counter+100;
        }

}

long double get_ms_time() {

    timeval tv;

    gettimeofday(&tv,NULL);

    return (static_cast<long double>(tv.tv_sec)*1000UL) + (static_cast<long double>(tv.tv_usec)/1000UL);

}

int main() {

    int numbers;
    Arr array_1(10);


    cout<<"Podaj, ile liczb wpisać do tablicy, program sprawdzi czas wykonania algorytmu n=n+100 dla podanej wartości:";
    cin>>numbers;

    long double start_time = get_ms_time();

    for(int i=0; i<numbers; i++)
    array_1.add_num(1);

    long double delta = get_ms_time() - start_time;

    cout<<"Czas wykonania dla algorytmu n=n+100 dla "<<numbers<<" liczb wynosi "<<delta<<"ms"<<endl;
}
