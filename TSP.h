/**
* Glowny algorytm rozwiazujacy problem komiwojazera 
*/

#pragma once
#include "Global.h"
#include "readFile.h"
#include "writeFile.h"

 ///Funkcja rekurencyjna celem, ktorej jest wyszukanie cyklu Hamiltona o jak najmniejszej sumie wag krawedzi 
 static void TSP(int);
 /// funkcja rozpoczynajaca algorytm, w niej inicujemy wierzcho³ek 0 oraz wypisujemy otrzymany wynik
 static void startAlgorithm(string fileName);
 /// funkcja odczytujaca dane z pliku i zapsujaca je w zmiennych wykorzystanych pozniej w algorytmie TSP
 static void storeData(string fileName);
 /// funkcja tworzaca i alokujaca pamiec 
 static void createDynamicStructures(string fileName);
 /// funkcja czyszczaca pamiec pod koniec programu
 static void clearAllocatedData();



