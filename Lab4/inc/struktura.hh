#ifndef struktura_hh
#define struktura_hh
#include <sys/time.h>


 /*!
* \brief Interfejs stopera.
*
* Zawiera metody umożliwiające mierzenie czasu w ms.
*/
class Main_timer {


public:
virtual long double get_ms_time()=0;
virtual void tim_start()=0;
virtual void tim_stop()=0;
virtual long double return_time()=0;
virtual ~Main_timer() {};

};


 /*!
* \brief Interfejs struktury danych.
*
* Zawiera metodę umożliwiającą dodawanie elementu do struktury.
*/
class DataStructure {


public:
virtual void add_num(int element)=0;
virtual ~DataStructure() {}

};

#endif
