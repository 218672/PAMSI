#ifndef ihasharray_hh
#define ihasharray_hh
#include "list.hh"
#include <string>


 /*!
* \brief Interfejs tablicy z haszowaniem.
*
* Zawiera metody umożliwiające operacje na tablicy.
*/
class IHashArray {

public:
virtual int hash(std::string surname)=0;
virtual void realloc_and_rehash()=0;
virtual ~IHashArray() {}

};

#endif
