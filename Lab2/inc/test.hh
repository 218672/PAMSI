#ifndef test_hh
#define test_hh
#include "irunnable.hh"

 /*!
* \brief Klasa rozruchowa.
*
* Zawiera metodę umożliwiającą uruchomienie programu.
*/
class Test : public IRunnable {

public:
void run(int Argc, char* Argv[]);
~Test();

};

#endif
