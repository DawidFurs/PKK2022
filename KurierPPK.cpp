/**
*   Autor projektu : Dawid Furs 
*/

#include <vector>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "TSP.cpp"
#include "readFile.h"
#include "Global.h"
#include "writeFile.h"


using namespace std;
/**@brief
* Funkcja main , zaczynam od ustawienia zmiennych string, które przechowywują 
* nazwy plików tekstowych które zostają podane podczas uruchamiania programu 
* z consoli 
* 
*/

int main(int argc, char *argv[])
{
    string inputFileName ;          /**< inputFileName zawiera nazwę pliku wejściowego */
    string outputFileName ;         ///@retval outputFileName zawiera nazwę pliku wyjściowego

    /**@brief Pętla sprawdzająca argumenty podane przy odpalaniu programu
    * w momencie znalezienia odpowiedniego argumentu zostaje on przypisany do
    * zmiennej string 
    * 
    */ 
    cout << "\nCommand-line arguments:\n";
    for (int count = 0; count < argc; count++) {
        if (argv[count][0] == '-')
        {   if(argv[count][1]=='i')
            inputFileName = argv[count+1];
        }
        if (argv[count][0] == '-')
        {   if(argv[count][1]=='o')
            outputFileName = argv[count+1];
        }
        cout << "  argv[" << count << "]   " << argv[count] << "\n";
    }

    cout << "Plik wejsciowy to : " << inputFileName;

    
    /// pierwsza funkcja sprawdzajaca czy plik do, ktorego chcemy otrzymac dostep istnieje
    checkFileExist(inputFileName);

    /// Tworzymy struktury dynamiczne i inicjujemy je
    createDynamicStructures(inputFileName);

    /// Odczytujemy dane wejściowe

    storeData(inputFileName);

    /// Rozpoczynamy algorytm

    startAlgorithm(outputFileName);

    /// Usuwamy tablice dynamiczne

    clearAllocatedData();


    return 0;
}