#ifndef hasharray_hh
#define hasharray_hh
#include "ihasharray.hh"
#include <string>
#include "list.hh"

 /*!
* \brief Klasa tablicy z haszowaniem.
*
* Zawiera metody umożliwiające operacje na tablicy.
*/
class HashArray : public IHashArray {

private:
List *arr=NULL; /*!< Wskaźnik na miejsce dla tablicy dynamicznej */
int size_of_arr=0; /*!< Rozmiar tablicy z haszowaniem */
int number_of_not_empty_lists=0; /*!< Liczba niepustych list */
friend class AsArray;

public:
HashArray(int number_of_elements);
~HashArray();

/**
 * Funkcja haszująca.
 *
 * \return wartość typu całkowitego
 *
 */
int hash(std::string name);

/**
 * Funkcja powiększająca i rehaszująca tablicę.
 *
 *
 */
void realloc_and_rehash();

};



#endif
