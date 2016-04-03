#ifndef list_hh
#define list_hh

template <typename E>
class IList {
public:
virtual void add(E elem, int i)=0;
virtual void remove(int i)=0;
virtual int get(int i)=0;
virtual int size()=0;

virtual ~IList() {};
};

#endif
