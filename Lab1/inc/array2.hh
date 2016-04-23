#ifndef array2_hh
#define array2_hh
#include "iarray.hh"
#include <cstddef>

// Algorytm powiększający tablicę o połowę podczas
// każdorazowego dodania nowego elementu w przypadku pełnej tablicy

 /*!
* \brief Klasa tablica.
*
* Zawiera metodę powiększającą tablicę dwukrotnie w przypadku każdego przepełnienia.
*/
class Arr_2 : public IArray {


private:
int *arr = NULL; /*!< Wskaźnik na miejsce w pamięci dla tablicy */
int counter = 0; /*!< Licznik miejsca */
int second_counter=0; /*!< Pomocniczy licznik miejsca */

public:
/**
 * Funkcja dodaje liczbe do tablicy.
 * W przypadku przepełnienia zwiększa rozmiar dwukrotnie.
 *
 * \param[in] liczba typu int
 *
 */
void add_num(int number); // dodaje liczbe do tablicy

Arr_2(int a);
~Arr_2();

};

#endif
