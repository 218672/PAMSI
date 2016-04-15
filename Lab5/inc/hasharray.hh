#ifndef hasharray_hh
#define hasharray_hh
#include "ihasharray.hh"
#include "list.hh"


class HashArray : public IHashArray {

private:
List *arr=NULL;

public:
HashArray(int number_of_elements);
~HashArray();
int hash(std::string name);
int add(std::string name, int hashed_index);
int remove(std::string name, int hashed_index);
int operator[](std::string arg);

};

#endif
