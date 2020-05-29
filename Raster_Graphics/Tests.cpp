#include <iostream>
#include <fstream>
#include "Common.h"
using namespace std;

//Съобщение, ако сме успяли да запазим информацията във файл.
void printSuccessMessage(string filePath)
{
	cout << endl;
	cout << "Successfully saved content in file: " << filePath << endl;
}

//Съобщение, ако не сме успяли да запазим информацията във файл.
void printErrorMessage(string filePath)
{
	cerr << endl;
	cerr << "There was a problem opening file with name: " << filePath << endl;
}

//Отваряне на файл.
void openFile(string filePath)
{
	ifstream inputFileStream;
	inputFileStream.open(filePath, ios::in);

	if (inputFileStream.is_open())
	{
		char lineFromFile[MAX_SIZE];

		while (!inputFileStream.eof())
		{
			inputFileStream.getline(lineFromFile, MAX_SIZE);
			cout << lineFromFile << endl;
		}

		inputFileStream.close();
		printSuccessMessage(filePath);
	}

	else
	{
		printErrorMessage(filePath);
	}
}

