#ifndef struktura_hh
#define struktura_hh
#include <sys/time.h>

// info: póki co testuję w algorytmy.cpp, tam gdzie dziedziczę trzy klasy. Odrębny plik .cpp tylko do wywołań dodam na spokojnie w domu

class Timer {
private:
long double time_of_start;
long double time_of_stop;

public:
long double get_ms_time();
void tim_start();
void tim_stop();
long double return_time();

};

class DataStructure {
Timer new_timer;

public:
virtual void init_by_zeros()=0;
virtual void add_num(int element)=0;
virtual ~DataStructure() {}

};

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

#endif
