#ifndef ipriorityqueue_hh
#define ipriorityqueue_hh

 /*!
* \brief Interfejs kolejki.
*
* Zawiera metody umożliwiające operacje na kolejce.
*/
template <typename E>
class IPriorityQueue {

public:
virtual void add(const E& elem, const int& value)=0;
virtual E remove()=0;
virtual int size()=0;

virtual ~IPriorityQueue() {};
};

#endif
