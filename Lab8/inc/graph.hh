#ifndef graph_hh
#define graph_hh
#include "igraph.hh"
#include "list.hh"
#include "queue.hh"

 /*!
* \brief Klasa grafu.
*
* Zawiera metody umożliwiające operacje na grafie.
*/
class Graph : public IGraph {

private:
List<int>* neighbours_list = NULL;
int **cost_matrix = NULL;
int size_of_neighbours_list = 0;
int* visited = NULL;

public:

Graph(int vertices);
~Graph();

/**
 * Metoda dodająca wierzchołek do grafu.
 * Ma zastosowanie w przypadku dodania dodatkowego wierzchołka po procedurze inicjacji całej struktury.
 *
 * \param[in] element typu int
 *
 */
void add_vertex(const int& v);

/**
 * Metoda dodająca krawędź do grafu.
 *
 * \param[in] element typu int
 * \param[in] element typu int
 *
 */
void add_edge(const int& x, const int& y, const int &cost);

/**
 * Metoda usuwająca wierzchołek z grafu.
 *
 * \param[in] element typu int
 *
 */
void remove_vertex(const int& v);

/**
 * Metoda usuwająca krawędź z grafu.
 *
 * \param[in] element typu int
 * \param[in] element typu int
 *
 */
void remove_edge(const int& x, const int& y);

/**
 * Metoda zwracająca listę sąsiadów danego wierzchołka.
 *
 * \param[in] element typu int
 *
 * \return lista sąsiedztwa danego wierzchołka
 */
List<int> get_neighbours(const int& v);

/**
 * Metoda sprawdzająca istnienie krawędzi pomiędzy dwoma wierzchołkami.
 *
 * \param[in] element typu int
 * \param[in] element typu int
 *
 * \return prawda lub fałsz
 */
bool is_connected(const int& x, const int& y);

/**
 * Metoda przeszukująca graf wszerz
 *
 * \param[in] element typu int
 *
 */
void search_path_BFS(const int& v);

/**
 * Metoda przeszukująca graf wgłąb
 *
 * \param[in] element typu int
 *
 */
void search_path_DFS(const int& v);

/**
 * Metoda pomocnicza dla search_path_DFS
 *
 * \param[in] element typu int
 *
 */
void visit_DFS(int i, const int& v);

/**
 * Metoda przeszukująca graf wszerz wykorzystująca branch and bound
 *
 * \param[in] element typu int
 *
 * \return liczba przebytych sciezek
 */
int BBsearch(const int &v);

/**
 * Metoda przeszukująca graf wszerz wykorzystująca branch and bound with extended list
 *
 * \param[in] element typu int
 *
 */
int BBsearch_with_extended_list(const int &v);


};

#endif
