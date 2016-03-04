#include <iostream>

using namespace std;

// Algorytm powiększający tablicę o 100 podczas
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
        cout<<"Powiekszono tablice o polowe"<<endl;
        }

}

int main() {

    int number, counter=0;
    Arr array_1;


    while(1) {
    cout<<"Wpisz numer do tablicy (ma ona wstepny rozmiar 10): ";
    cin>>number;
    array_1.add_num(number);
    }
}
