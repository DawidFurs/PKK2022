#pragma once
#include"writeFile.h"


void writeToFile(ofstream& outputFile, int x )
{
	outputFile << x << " ";
}

void writeToFile(ofstream& outputFile, string x)
{
	outputFile << endl <<x;
}