#ifndef irunnable_hh
#define irunnable_hh

 /*!
* \brief Interfejs klasy rozruchowej.
*
* Zawiera metodę umożliwiającą uruchomienie programu.
*/
class IRunnable {
public:

virtual void run(int Argc, char* Argv[])=0;

};

#endif
