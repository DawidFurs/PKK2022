#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Global.h"

using namespace ::std;
/// sprawdzanie czy plik tekstowy istnieje
void checkFileExist(string fileName);
/// zliczanie wszyskich wyrazow w pliku z wyjatkiem znakow szczegolnych
int countWords(string fileName);
/// zliczanie ilosci wierzcholkow
int amountOfVertex(string fileName);
/// zlicanie ilosci krawedzi
int amoutOfEdges(string fileName);
/// funkcja zapisujaca dane do vektora 
vector <int> readDataEdgeWeight(string fileName);
/// funkcja pozwalajaca konvertowac vector 1d do vectora 2d
vector<vector<int>> create2Dvector (vector<int> a, int m, int n);  

