#ifndef stack_hh
#define stack_hh

template <typename E>
class IStack {
public:
virtual void push(const E& elem)=0;
virtual E pop()=0;
virtual int size()=0;

virtual ~IStack() {};
};

#endif
