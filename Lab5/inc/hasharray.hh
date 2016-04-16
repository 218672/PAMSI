#ifndef hasharray_hh
#define hasharray_hh
#include "ihasharray.hh"
#include <string>
#include "list.hh"


class HashArray : public IHashArray {

private:
List *arr=NULL;
int size_of_arr=0;
friend class AsArray;

public:
HashArray(int number_of_elements);
~HashArray();
int hash(std::string name);

};



#endif
