#ifndef iasarray_hh
#define iasarray_hh

class IAsArray {

public:
virtual bool is_empty()=0;
virtual void insert(std::string name, int hashed_index)=0;

}

#endif
