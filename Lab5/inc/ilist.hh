#ifndef ilist_hh
#define ilist_hh


class IList {

public:
virtual void add(const std::string& elem, int i)=0;
virtual E remove(int i)=0;
virtual int size()=0;

virtual ~IList() {};
};

#endif
