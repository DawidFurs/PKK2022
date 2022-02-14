#pragma once
#include <vector>
#include <iostream>
#include "TSP.h"




void TSP(int v)
{
    int u;

    Sh[shptr++] = v;              // zapami�tujemy na stosie bie��cy wierzcho�ek

    if (shptr < n)                  // je�li brak �cie�ki Hamiltona, to jej szukamy
    {
        visited[v] = true;          // Oznaczamy bie��cy wierzcho�ek jako odwiedzony
        for (u = 0; u < n; u++)       // Przegl�damy s�siad�w wierzcho�ka v
            if (A[v][u] && !visited[u]) // Szukamy nieodwiedzonego jeszcze s�siada
            {
                dh += W[v][u];        // Dodajemy wag� kraw�dzi v-u do sumy
                TSP(u);                 // Rekurencyjnie wywo�ujemy szukanie cyklu Hamiltona
                dh -= W[v][u];        // Usuwamy wag� kraw�dzi z sumy
            }
        visited[v] = false;         // Zwalniamy bie��cy wierzcho�ek
    }
    else if (A[v0][v])         // Je�li znaleziona �cie�ka jest cyklem Hamiltona
    {
        dh += W[v][v0];           // to sprawdzamy, czy ma najmniejsz� sum� wag
        if (dh < d)                   // Je�li tak, 
        {
            d = dh;                      // To zapami�tujemy t� sum�
            for (u = 0; u < shptr; u++) // oraz kopiujemy stos Sh do S
                S[u] = Sh[u];
            sptr = shptr;
        }
        dh -= W[v][v0];           // Usuwamy wag� kraw�dzi v-v0 z sumy
    }
    shptr--;                         // Usuwamy bie��cy wierzcho�ek ze �cie�ki
}