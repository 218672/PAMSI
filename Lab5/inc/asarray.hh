#ifndef asarray_hh
#define asarray_hh
#include <string>
#include "list.hh"
#include "hasharray.hh"
#include "iasarray.hh"

class AsArray : public IAsArray {

private:
HashArray *hasharr=NULL;

public:
AsArray(int number_of_elements);
~AsArray();
void insert(const std::string& key, const int& value);
void remove(const std::string& key);
int search(const std::string& key);
bool read_from_file(std::string file_name);
int operator[](const std::string& key);

};


#endif
