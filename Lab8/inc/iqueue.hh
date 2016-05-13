#ifndef iqueue_hh
#define iqueue_hh

 /*!
* \brief Interfejs kolejki.
*
* Zawiera metody umożliwiające operacje na kolejce.
*/
template <typename E>
class IQueue {

public:
virtual void add(const E& elem)=0;
virtual E remove()=0;
virtual int size()=0;

virtual ~IQueue() {};
};

#endif
