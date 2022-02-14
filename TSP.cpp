#pragma once
#include <vector>
#include <iostream>
#include "TSP.h"




void TSP(int v)
{
    int u;

    Sh[shptr++] = v;              // zapamiêtujemy na stosie bie¿¹cy wierzcho³ek

    if (shptr < n)                  // jeœli brak œcie¿ki Hamiltona, to jej szukamy
    {
        visited[v] = true;          // Oznaczamy bie¿¹cy wierzcho³ek jako odwiedzony
        for (u = 0; u < n; u++)       // Przegl¹damy s¹siadów wierzcho³ka v
            if (A[v][u] && !visited[u]) // Szukamy nieodwiedzonego jeszcze s¹siada
            {
                dh += W[v][u];        // Dodajemy wagê krawêdzi v-u do sumy
                TSP(u);                 // Rekurencyjnie wywo³ujemy szukanie cyklu Hamiltona
                dh -= W[v][u];        // Usuwamy wagê krawêdzi z sumy
            }
        visited[v] = false;         // Zwalniamy bie¿¹cy wierzcho³ek
    }
    else if (A[v0][v])         // Jeœli znaleziona œcie¿ka jest cyklem Hamiltona
    {
        dh += W[v][v0];           // to sprawdzamy, czy ma najmniejsz¹ sumê wag
        if (dh < d)                   // Jeœli tak, 
        {
            d = dh;                      // To zapamiêtujemy tê sumê
            for (u = 0; u < shptr; u++) // oraz kopiujemy stos Sh do S
                S[u] = Sh[u];
            sptr = shptr;
        }
        dh -= W[v][v0];           // Usuwamy wagê krawêdzi v-v0 z sumy
    }
    shptr--;                         // Usuwamy bie¿¹cy wierzcho³ek ze œcie¿ki
}