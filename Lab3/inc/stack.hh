#ifndef stack_hh
#define stack_hh

template <typename E>
class IStack {
public:
virtual E push(E elem)=0;
virtual void pop()=0;
virtual int size()=0;

virtual ~IStack() {};
};

#endif
