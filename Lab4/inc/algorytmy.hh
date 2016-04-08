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

class Arr_second_type: public DataStructure {

private:
int *arr = NULL; // wskaźnik na miejsce w pamięci
int counter = 0; // licznik miejsca
int second_counter=0; // licznik pomocniczy

public:
void add_num(int number); // dodaje liczbe do tablicy
void quick_sort(int left, int right);
void show_arr();


Arr_second_type(int a);
~Arr_second_type();

};

#endif
