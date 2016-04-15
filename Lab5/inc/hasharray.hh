#ifndef hasharray_hh
#define hasharray_hh
#include "ihasharray.hh"
#include "asarray.hh"

class HashArray : public IHashArray {

private:
AsArray *asarr=NULL;

public:
HashArray(int number_of_elements);
~HashArray();
int hash(std::string name);
int insert_in_asarr(std::string name, int hashed_index);
int operator[](std::string arg);

};

#endif
