#ifndef array1_hh
#define array1_hh
#include "iarray.hh"
#include <cstddef>

// Algorytm powiększający tablicę poprzez zmianę rozmiaru o 1 podczas
// każdorazowego dodawania nowego elementu


 /*!
* \brief Klasa tablica.
*
* Zawiera metodę powiększającą tablicę o 1 w przypadku każdego przepełnienia.
*/
class Arr_1 : public IArray {

private:
int *arr = NULL; /*!< Wskaźnik na miejsce w pamięci dla tablicy */
int counter = 0; /*!< Licznik miejsca */

public:
/**
 * Funkcja dodaje liczbe do tablicy.
 * W przypadku przepełnienia zwiększa rozmiar o 1.
 *
 * \param[in] liczba typu int
 *
 */
void add_num(int number);

Arr_1(int a);
~Arr_1();

};

#endif
