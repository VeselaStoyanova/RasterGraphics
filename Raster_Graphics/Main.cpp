#include <iostream>
#include <fstream>
#include "Image.h"
#include "Matrix.h"

using namespace std;

void testMatrix()
{
	Matrix firstMatrix = Matrix();
	int** ary = new int* [2];

	for (int i = 0; i < 2; ++i)
	{
		ary[i] = new int[3];
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
		{
			ary[i][j] = (i+1)*(j+1);
		}
	}

	//{ {1,2,3},{4,5,6}};
	Matrix secondMatrix = Matrix(2,3, ary);
	cout << secondMatrix << endl;

	cin >> secondMatrix;
	cout << secondMatrix << endl;
}

	//Съобщение, ако сме успяли да запазим информацията във файл.
void printSuccessMessage(const char* filePath)
{
	cout << endl;
	cout << "Successfully saved content in file: " << filePath << endl;
}

	//Съобщение, ако не сме успяли да запазим информацията във файл.
void printErrorMessage(const char* filePath)
{
	cerr << endl;
	cerr << "There was a problem opening file with name: " << filePath << endl;
}

void openFile()
{
	const char* filePath = "myFile.txt";

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

int main()
{
	testMatrix();
}