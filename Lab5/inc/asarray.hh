#ifndef asarray_hh
#define asarray_hh
#include "list.hh"

class AsArray : public IAsArray {

private:
List *arr=NULL;
int size_of_arr=0;

public:
AsArray();
~AsArray();
bool is_empty();
void insert(std::string name, int hashed_index);

}

#endif
