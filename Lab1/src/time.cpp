#include <sys/time.h>

using namespace std;

long double get_ms_time() {

    timeval tv;

    gettimeofday(&tv,NULL);

    return (static_cast<long double>(tv.tv_sec)*1000UL) + (static_cast<long double>(tv.tv_usec)/1000UL);

}

int main() {

    long double startTime = get_ms_time();
    long double delta = get_ms_time() - start_time;

}
