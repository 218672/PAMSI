#ifndef ihasharray_hh
#define ihasharray_hh
#include "list.hh"
#include <string>


class IHashArray {

public:
virtual int hash(std::string surname)=0;
virtual ~IHashArray() {}

};

#endif
