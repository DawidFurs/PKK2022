#pragma once
#include "readFile.h"


void checkFileExist() {
	ifstream file;

	file.open("text.txt");

	if (!file.is_open()) {
		cout << "Error!!";
	}
}

int amountOfVertex() {
	ifstream file;

	file.open("text.txt");

	int  temp[9999] = { NULL }, x, i = 0, j = 1;

	while (file >> x)
	{
		temp[i] = x;
		i++;
	}

	int size = sizeof(temp) / sizeof(temp[0]);

	for (int k = 0; k <= i; k += 3)
	{
		if (temp[k] != temp[k + 3])
		{
			j++;
		}
	}


	return j;
}

int amoutOfEdges() {
	ifstream file;

	file.open("text.txt");

	int x, i = 0, j;

	while (file >> x) {
		i++;
	}
	j = i;
	
	return (j/3);

}