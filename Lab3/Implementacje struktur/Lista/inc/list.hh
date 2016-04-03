#ifndef list_hh
#define list_hh

template <typename E>
class IList {
public:
virtual void add(const E& elem, int i)=0;
virtual E remove(int i)=0;
virtual int size()=0;

virtual ~IList() {};
};

#endif
