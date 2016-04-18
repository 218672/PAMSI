#ifndef timer_hh
#define timer_hh
#include <sys/time.h>
#include "maintimer.hh"

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
