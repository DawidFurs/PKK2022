#include <vector>
#include <iostream>
#include <vector>
#include "TSP.cpp"
#include "readFile.h"


using namespace std;


//**********************
//*** Program główny ***
//**********************

int main()
{
    checkFileExist();

    int number{ amountOfVertex() };
    int number1{ amoutOfEdges() };
    n = number;
    m = number1;


    int i, j, x, y, z;


    // Tworzymy struktury dynamiczne i inicjujemy je

    S = new int[n];
    Sh = new int[n];
    visited = new bool[n];
    A = new bool* [n];
    for (i = 0; i < n; i++)
    {
        A[i] = new bool[n];
        vector<int> temp;
        for (j = 0; j < n; j++)
        {
            A[i][j] = false;
            temp.push_back(0);
        }
        visited[i] = false;
        W.push_back(temp);
    }
    sptr = shptr = 0;

    // Odczytujemy dane wejściowe

    for (i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        A[x][y] = A[y][x] = true; // Krawędź x-y
        W[x][y] = W[y][x] = z;    // Waga krawędzi x-y
    }

    cout << endl;

    // Rozpoczynamy algorytm

    d = MAXINT;
    dh = v0 = 0;
    TSP(v0);
    if (sptr)
    {
        for (i = 0; i < sptr; i++) cout << S[i] << " ";
        cout << v0 << endl;
        cout << "d = " << d << endl;
    }
    else cout << "NO HAMILTONIAN CYCLE" << endl;

    cout << endl;

    // Usuwamy tablice dynamiczne

    delete[] S;
    delete[] Sh;
    delete[] visited;

    for (i = 0; i < n; i++)
    {
        delete[] A[i];
    }

    delete[] A;


    return 0;
}