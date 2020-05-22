#pragma once
#include <iostream>
#include "Common.h"
using namespace std;

class Matrix
{
private:
	int rows;
	int columns;
	int** pixels;

	void copy(const Matrix& other);
	void erase();

public:
	Matrix();
	Matrix(int rows, int columns, int **pixels);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	bool operator==(const Matrix& other);
	~Matrix();

	//Setters
	void setRows(const int rows);
	void setColomns(const int columns);
	void setPixels(const int **pixels);

	//Getters
	int getRows() const;
	int getColomns() const;
	int** getPixels() const;

	friend ostream& operator<<(ostream& output, const Matrix& m);
	friend istream& operator>>(istream& input, Matrix& m);
};
