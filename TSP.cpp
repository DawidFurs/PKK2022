#pragma once
#include <vector>
#include <iostream>
#include "TSP.h"





void TSP(int v)
{
    int u;
    /// zapamietujemy na stosie biezacy wierzcho³ek
    Toph[stackh++] = v;

    if (stackh < n)             /// jesli brak sciezki Hamiltona, to jej szukamy     
    {                           /// Oznaczamy biezacy wierzcholek jako odwiedzony
        visited[v] = true;          /// Przegladamy sasiadow wierzcholka v
        for (u = 0; u < n; u++)       /// Szukamy nieodwiedzonego jeszcze sasiada
            if (A[v][u] && !visited[u]) 
            {                               /// Dodajemy wage krawedzi v-u do sumy
                dh += W[v][u];          /// Rekurencyjnie wywolujemy szukanie cyklu Hamiltona
                TSP(u);                 /// Usuwamy wage krawêdzi z sumy
                dh -= W[v][u];        
            }                                   /// Zwalniamy biezacy wierzcholek
        visited[v] = false;         
    }                           /// Jesli znaleziona sciezka jest cyklem Hamiltona
    else if (A[v0][v])         
    {                               /// to sprawdzamy, czy ma najmniejsz¹ sumê wag
        dh += W[v][v0];           /// Jesli tak, 
        if (dh < d)                   
        {                           /// To zapamietujemy te sume
            d = dh;                      /// oraz kopiujemy stos Sh do S
            for (u = 0; u < stackh; u++)
                Top[u] = Toph[u];
            stack = stackh;
        }                           /// Usuwamy wage krawedzi v-v0 z sumy
        dh -= W[v][v0];           
    }                               /// Usuwamy biezacy wierzcholek ze sciezki
    stackh--;
}

void startAlgorithm(string fileName) 
{                                     ///uchwyt do pliku
    ofstream outputFile;            /// otiwranie pliku tekstowego
    outputFile.open(fileName);      
                                     /// maksymalna droga, potrzebna do porownania i wyszukania najkrotszej trasy
    d = MAXINT;                     /// ustawianie poczatkowego i koncowego wierzcholka
    dh = v0 = 0;                   /// rekurencja TSP
    TSP(v0);                        /// sprawdzanie czy wierzcholek istnieje
    if (stack)
    {

        for (int i = 0; i < stack; i++)
        {                                           /// wypisywanie wartosci kolejnych przebytych drug ze stosu
            writeToFile(outputFile, Top[i]);    
        }

        writeToFile(outputFile, v0);                    /// suma wag jaka do pokonania trasy 
        writeToFile(outputFile, "path cost = ");    
        writeToFile(outputFile, d);
    }                                                   ///informacja o braku cyklu Hamiltona
    else writeToFile(outputFile, "NO HAMILTON CYCLE");  


}

static void storeData(string fileName)
{

                                                                 /// wpisanie do vectora wartosci z pliku tekstowego
    vector <int> temp{ readDataEdgeWeight(fileName) };  
                                                                /// sprawdzanie ilosci wyrazow w pliku sluza do inicjowania macierzy wektorow 
    int numberofWords{ countWords(fileName) };  
    int Words = numberofWords;

    for (int k = 0; k < Words; k += 3)
    {                                                                   /// Krawedz x-y
        A[temp[k]][temp[k + 1]] = A[temp[k + 1]][temp[k]] = true;       /// Waga krawedz x-y
        W[temp[k]][temp[k + 1]] = W[temp[k + 1]][temp[k]] = temp[k + 2];    

    }
}

static void createDynamicStructures(string fileName) {
                                                                /// ilosc wierzcholkow potrzebna do inicjowania pamieci 
    int number{ amountOfVertex(fileName) }; 
    n = number;
                                                        
    Top = new int[n];
    Toph = new int[n];
    visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        vector<int> tempA;
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            tempA.push_back(false);
            temp.push_back(0);
        }
        visited[i] = false;
        W.push_back(temp);
        A.push_back(tempA);
    }
    stack = stackh = 0;


}

void clearAllocatedData()
{                                                   /// czyszczenie zaalokowanej pamieci
    delete[] Top;
    delete[] Toph;
    delete[] visited;
}