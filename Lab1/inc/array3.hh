#ifndef array3_hh
#define array3_hh
#include "iarray.hh"
#include <cstddef>

// Algorytm powiększający tablicę o 100 podczas
// każdorazowego dodania nowego elementu w przypadku pełnej tablicy


 /*!
* \brief Klasa tablica.
*
* Zawiera metodę powiększającą tablicę o 100 w przypadku każdego przepełnienia.
*/
class Arr_3 : public IArray {

private:
int *arr = NULL; /*!< Wskaźnik na miejsce w pamięci dla tablicy */
int counter = 0; /*!< Licznik miejsca */
int second_counter=0; /*!< Pomocniczy licznik miejsca */

public:
/**
 * Funkcja dodaje liczbe do tablicy.
 * W przypadku przepełnienia zwiększa rozmiar o 100.
 *
 * \param[in] liczba typu int
 *
 */
void add_num(int number); // dodaje liczbe do tablicy

Arr_3(int a);
~Arr_3();

};

#endif
