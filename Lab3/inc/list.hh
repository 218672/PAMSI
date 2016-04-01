#ifndef list_hh
#define list_hh

class IList {
public:
virtual void add(int elem, int i)=0;
virtual void remove(int i)=0;
virtual int get(int i)=0;
virtual int size()=0;

virtual ~IList() {};
};

#endif
