#ifndef algorytmy_hh
#define algorytmy_hh
#include "struktura.hh"

class Timer: public Main_timer {
private:
long double time_of_start;
long double time_of_stop;

public:
long double get_ms_time();
void tim_start();
void tim_stop();
long double return_time();
~Timer() {};

};

class Array: public DataStructure {

private:
int *arr = NULL; // wskaźnik na miejsce w pamięci
int *tmp = NULL;
int counter = 0; // licznik miejsca
int second_counter=0; // licznik pomocniczy
int arr_size=0;

public:
void add_num(int number); // dodaje liczbe do tablicy
void quick_sort_random(int left, int right); // wybór pivota ze środka tablicy
void quick_sort_last(int left, int right); // wybór pivota z końca tablicy
void quick_sort_mean(int left, int right); // wybór pivota na zasadzie środkowy z trzech
void show_arr();
void merge(int left, int medium, int right);
void merge_sort(int left, int right);


Array(int a);
~Array();

};

#endif
