#pragma once
#include <vector>
const int MAXINT = 2147483647;

// Zmienne globalne


static int n, m, v0, d, dh, sptr, shptr;
static bool** A;                         // Macierz s�siedztwa
static std::vector<std::vector<int>> W;                          // Macierz wag kraw�dzi
static int* S, * Sh;                      // Stosy w tablicy
static bool* visited;                    // Tablica odwiedzin