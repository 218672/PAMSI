#ifndef algorytmy_hh
#define algorytmy_hh
#include "struktura.hh"
#include <cstddef>

 /*!
* \brief Klasa stoper.
*
* Zawiera metody umożliwiające pomiar czasu wykonywania algorytmów.
*/
class Timer: public Main_timer {

private:
long double time_of_start;
long double time_of_stop;

public:
/**
 * Funkcja mierzy rzeczywisty czas w ms.
 *
 *
 * \return czas, jeśli zmierzono
 */
long double get_ms_time();
/**
 * Funkcja włączająca stoper.
 *
 *
 */
void tim_start();
/**
 * Funkcja wyłączająca stoper.
 *
 *
 */
void tim_stop();
/**
 * Funkcja zwracająca zmierzony czas w ms.
 *
 *
 * \return czas, jeśli zmierzono
 */
long double return_time();

~Timer() {};

};


 /*!
* \brief Klasa struktury danych.
*
* Zawiera metodę umożliwiającą dodanie danej do struktury.
*/
class Arr_first_type: public DataStructure {

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
void add_num(int number); // dodaje liczbe do tablicy

Arr_first_type(int a);
~Arr_first_type();

};

class Arr_second_type: public DataStructure {
 /*!
* \brief Klasa struktury danych.
*
* Zawiera metodę umożliwiającą dodanie danej do struktury.
*/


private:
int *arr = NULL; /*!< Wskaźnik na miejsce w pamięci dla tablicy */
int counter = 0; /*!< Licznik miejsca */
int second_counter=0; /*!< Pomocniczy licznik miejsca */

public:
/**
 * Funkcja dodaje liczbe do tablicy.
 * W przypadku przepełnienia podwaja rozmiar tablicy.
 *
 * \param[in] liczba typu int
 *
 */
void add_num(int number);

Arr_second_type(int a);
~Arr_second_type();

};

class Arr_third_type: public DataStructure {
 /*!
* \brief Klasa struktury danych.
*
* Zawiera metodę umożliwiającą dodanie danej do struktury.
*/


private:
int *arr = NULL; /*!< Wskaźnik na miejsce w pamięci dla tablicy */
int counter = 0; /*!< Licznik miejsca */
int second_counter=0; /*!< Pomocniczy licznik miejsca */

public:
/**
 * Funkcja dodaje liczbe do tablicy.
 * W przypadku przepełnienia zwiększa rozmiar o 1.
 *
 * \param[in] liczba typu int
 *
 */
void add_num(int number);

Arr_third_type(int a);
~Arr_third_type();

};

#endif
