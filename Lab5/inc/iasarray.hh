#ifndef iasarray_hh
#define iasarray_hh
#include <string>


 /*!
* \brief Interfejs tablicy asocjacyjnej.
*
* Zawiera metody umożliwiające operacje na tablicy.
*/
class IAsArray {

public:
virtual void insert(const std::string& key, const int& value)=0;
virtual void remove(const std::string& key)=0;
virtual int search(const std::string& key)=0;
virtual void read_from_file(std::string file_name, int amount_of_data)=0;
virtual void search_with_file(std::string file_name, int amount_of_data)=0;
virtual int operator[](const std::string& key)=0;
virtual ~IAsArray() {}

};

#endif
