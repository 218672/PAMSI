#include <iostream>
#include "algorytmy.hh"
#include "struktura.hh"

Array::Array(int a) {
//konstruktor - tablice inicjujemy od razu iloscia miejsc
    arr = new int [a];
    tmp = new int [a];

    for(int i=0; i<a; i++)
        arr[i]=0;

}

Array::~Array() {
// destruktor - zwalniamy pamiec
delete []arr;

}

void Array::add_num(int number) {

    if (counter<10+second_counter) { // jesli niepelna to zapelniaj
        arr[counter]=number;
        counter++;
        arr_size++;
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
        arr_size++;
        }
}

void Array::quick_sort_random(int left, int right) {
    int i = left;
    int j = right;
    int x = arr[(left+right)/2];
    do {
        while(arr[i]<x)
             i++;
        while(arr[j]>x)
             j--;
        if(i<=j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while(i<=j);

    if(left<j)
    quick_sort_random(left, j);

    if(right>i)
    quick_sort_random(i, right);
}

void Array::quick_sort_last(int left, int right) {
    int i = left;
    int j = right;
    int x = arr[right];
    do {
        while(arr[i]<x)
             i++;
        while(arr[j]>x)
             j--;
        if(i<=j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while(i<=j);

    if(left<j)
    quick_sort_last(left, j);

    if(right>i)
    quick_sort_last(i, right);
}

void Array::quick_sort_mean(int left, int right) {
    int i = left;
    int j = right;
    int y[] = {arr[left], arr[(left+right)/2] ,arr[right]};

     for (int i=0; i<3; i++) {
     if (y[i]>y[i+1])
     std::swap(y[i], y[i+1]);
     }

    int x = y[1];
    do {
        while(arr[i]<x)
             i++;
        while(arr[j]>x)
             j--;
        if(i<=j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while(i<=j);

    if(left<j)
    quick_sort_mean(left, j);

    if(right>i)
    quick_sort_mean(i, right);
}

void Array::merge(int left, int middle, int right) {
int i=left, j=middle+1, k=0; // zmienne pomocnicze

while (i<=middle && j<=right) {
    if (arr[j]<arr[i]) {
    tmp[k] = arr[j];
    j++;
    }
    else {
    tmp[k] = arr[i];
    i++;
    }
k++;
}

if (i<=middle) {
    while (i<=middle) {
    tmp[k] = arr[i];
    i++;
    k++;
    }
}
else {
    while (j <= right) {
    tmp[k] = arr[j];
    j++;
    k++;
    }
}

for (i = 0; i <= right-left; i++)
arr[left+i] = tmp[i];

}

void Array::merge_sort(int left, int right) {

int middle;

if (left != right) {
middle = (left + right)/2;
merge_sort(left, middle);
merge_sort(middle+1, right);
merge(left, middle, right);
}
}

void Array::show_arr() {
    for(int i=0; i<counter; i++)
        std::cout<<arr[i]<<" ";
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
