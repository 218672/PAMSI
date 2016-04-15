#ifndef ihasharray_hh
#define ihasharray_hh


class IHashArray {

public:
virtual bool is_empty()=0;
virtual int hash(std::string name)=0;
virtual void add(std::string name, int hashed_index)=0;
virtual void remove(std::string name, int hashed_index)=0;
virtual ~IHashArray() {}

};

#endif
