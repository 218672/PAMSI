#ifndef maintimer_hh
#define maintimer_hh

class Main_timer {

public:
virtual long double get_ms_time()=0;
virtual void tim_start()=0;
virtual void tim_stop()=0;
virtual long double return_time()=0;
virtual ~Main_timer() {};

};

#endif
