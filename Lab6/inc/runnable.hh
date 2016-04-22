#ifndef runnable_hh
#define runnable_hh
#include "irunnable.hh"

 /*!
* \brief Klasa rozruchowa.
*
* Zawiera metodę umożliwiającą uruchomienie programu.
*/
class Runnable : public IRunnable {

public:
void run();

};

#endif
