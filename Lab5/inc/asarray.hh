#ifndef asarray_hh
#define asarray_hh
#include <string>
#include "list.hh"
#include "hasharray.hh"
#include "iasarray.hh"


 /*!
* \brief Klasa tablicy asocjacyjnej.
*
* Zawiera metody umożliwiające operacje na tablicy.
*/
class AsArray : public IAsArray {

private:
HashArray *hasharr=NULL; /*!< Wskaźnik na miejsce dla tablicy haszującej */

public:
AsArray(int number_of_elements);
~AsArray();

/**
 * Funkcja umożliwiająca wstawienie elementu do tablicy.
 *
 *
 */
void insert(const std::string& key, const int& value);

/**
 * Funkcja usuwająca element o podanym kluczu.
 *
 *
 */
void remove(const std::string& key);

/**
 * Funkcja wyszukująca element o podanym kluczu i zwracająca jego wartość.
 *
 * \return wartość typu całkowitego
 *
 */
int search(const std::string& key);

/**
 * Funkcja wczytująca dane do tablicy.
 * Napisana została na potrzeby testowe.
 *
 *
 */
void read_from_file(std::string file_name, int amount_of_data);

/**
 * Funkcja wyszukująca dane na podstawie znanego klucza.
 * Napisana została na potrzeby testowe.
 *
 */
void search_with_file(std::string file_name, int amount_of_data);

/**
 * Przeciążenie operatora indeksowania.
 * Umożliwia wypisywanie elementu o podanym kluczu korzystając z indeksowania.
 *
 */
int operator[](const std::string& key);

};


#endif
