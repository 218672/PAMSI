#ifndef queue_hh
#define queue_hh

template <typename E>
class IQueue {
public:
virtual void add_back(E elem)=0;
virtual E remove_front()=0;
virtual int size()=0;

virtual ~IQueue() {};
};

#endif
