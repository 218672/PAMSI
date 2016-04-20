#ifndef list_hh
#define list_hh
#include "ilist.hh"
#include <string>

class Node;
class List;

 /*!
* \brief Klasa węzła listy.
*
* Zawiera element węzła oraz wskaźnik na następny węzeł.
*/
class Node {
friend class List; // przyznajemy dostep klasie List

private:
std::string elem; /*!< Element listy */
int number; /*!< Drugi element listy */
Node* next; /*!< Wskaźnik na kolejny węzeł */

};

 /*!
* \brief Klasa listy.
*
* Zawiera metody umożliwiające operacje na liście.
*/
class List : public IList {

private:
Node* front; /*!< Wskaźnik na początek listy */
Node* end; /*!< Wskaźnik na koniec listy */
int list_size=0; /*!< Rozmiar listy */

public:
List() {
front = NULL; // inicjujemy NULLami poczatek i koniec
end = NULL;
};
~List() {};

/**
 * Funkcja dodająca element do listy
 *
 * \param[in] element typu string
 * \param[in] element typu int
 * \param[in] pozycja i
 *
 */
void add(const std::string& elem, const int& phone_number, int i);

/**
 * Funkcja usuwająca element z listy
 * Wyrzuca wyjątek EmptyListException jeśli lista jest pusta oraz WrongIndexException jeśli wybrano zły indeks.
 *
 * \return Element typu int
 *
 */
int remove(int i);

/**
 * Funkcja zwracająca rozmiar listy
 *
 * \return Rozmiar kolejki typu int
 *
 */
int size();

/**
 * Funkcja wyświetlająca listę
 *
 *
 */
void show_list();

/**
 * Funkcja zwracająca element typu int o podanym kluczu
 *
 * \param[in] element typu string
 *
 * \return element typu int
 *
 */
int search_by_key(std::string key);

/**
 * Funkcja zwracająca pozycję danego klucza
 *
 * \param[in] element typu string
 *
 * \return pozycja typu int
 *
 */
int find_key_position(std::string key);

/**
 * Funkcja zwracająca klucz pierwszego elementu listy
 *
 * \return klucz pierwszego elementu listy
 *
 */
std::string get_hashed_key(); // znajduje zhashowany klucz będący identyfikatorem całej listy

};

#endif
