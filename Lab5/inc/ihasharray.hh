#ifndef ihasharray_hh
#define ihasharray_hh


class IHashArray {

public:
virtual int hash(std::string name)=0;
virtual void insert_in_asarr(std::string name, int hashed_index)=0;
virtual ~IHashArray() {}

};

#endif
