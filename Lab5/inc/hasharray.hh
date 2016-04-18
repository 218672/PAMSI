#ifndef hasharray_hh
#define hasharray_hh
#include "ihasharray.hh"
#include <string>
#include "list.hh"


class HashArray : public IHashArray {

private:
List *arr=NULL;
int size_of_arr=0;
int number_of_not_empty_lists=0;
friend class AsArray;

public:
HashArray(int number_of_elements);
~HashArray();
int hash(std::string name);
void realloc_and_rehash();

};



#endif
