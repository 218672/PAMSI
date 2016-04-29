#ifndef ilist_hh
#define ilist_hh

 /*!
* \brief Interfejs listy.
*
* Zawiera metody umożliwiające operacje na liście.
*/
template <typename E>
class IList {

public:
virtual void add(const E& elem, int i)=0;
virtual E remove(int i)=0;
virtual int size()=0;

virtual ~IList() {};
};

#endif
