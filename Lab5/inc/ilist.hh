#ifndef ilist_hh
#define ilist_hh
#include <string>


class IList {

public:
virtual void add(const std::string& elem, const int& phone_number, int i)=0;
virtual int remove(int i)=0;
virtual int size()=0;
virtual int search_by_key(std::string key)=0;
virtual int find_key_position(std::string key)=0;
virtual std::string get_hashed_key()=0;

virtual ~IList() {};
};

#endif
