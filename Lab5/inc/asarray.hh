#ifndef asarray_hh
#define asarray_hh
#include "hasharray.hh"

class AsArray : public IAsArray {

private:
HashArray *hasharr=NULL;

public:
AsArray();
~AsArray();
int& operator[](const& string name);

}

#endif
