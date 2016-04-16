#ifndef iasarray_hh
#define iasarray_hh
#include <string>

class IAsArray {

public:
virtual void insert(const std::string& key, const int& value)=0;
virtual void remove(const std::string& key)=0;
virtual int search(const std::string& key)=0;
virtual int operator[](const std::string& key)=0;
virtual ~IAsArray() {}

};

#endif
