#pragma once
#include <vector>
/// Zmienne globalne
///@param MAXINT sluzy jako "kotwica" na jej podstawie wyszukiwana jest trasa o najmniejszym koszcie 
const int MAXINT = 2147483647;



																///@param n lb wierzcholkow w grafie
																///@param m lb krawedzi w grafie
																///@param v0 poczatkowy wierzcholek
																///@param d	dlugosc przebytej drogi
																///@param dh pomocnicza dlugosc przebytej drogi
																///@param sptr	stos
																///@param shptr pomocniczy stos
static int n, m, v0, d, dh, stack, stackh;						///@param A Macierz sasiedztwa
static std::vector<std::vector<int>> A;							///@param W Vector wag krawedzi
static std::vector<std::vector<int>> W;							///@param Top Stosy w tablicy
																///@param Toph pomocniczy stos tablicy
static int* Top, * Toph;										///@param visited Tablica odwiedzin
static bool* visited;                   