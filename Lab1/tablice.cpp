#include <iostream>

using namespace std;

class Arr {
public:
int *arr = new int [10];
int counter = 0;

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
        arr=new_a;
        delete [] new_a;
        new_a=NULL;
        counter++;
        cout<<"Powiekszono tablice o 1"<<endl;
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
