#include <iostream>
#include <fstream>
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
			ary[i][j] = (i + 1) * (j + 1);
		}
	}

	//{ {1,2,3},{4,5,6}};
	//Matrix secondMatrix = Matrix(2,3, ary);
	//cout << secondMatrix << endl;

	//cin >> secondMatrix;
	//cout << secondMatrix << endl;
}


