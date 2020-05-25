#pragma once
#include <iostream>
#include "Common.h"
#include "Pixel.h"
using namespace std;

class Matrix
{
private:
	int rows;
	int columns;
	Pixel** pixels;

	void copy(const Matrix& other);
	void erase();

public:
	Matrix();
	Matrix(int rows, int columns, Pixel** pixels);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	bool operator==(const Matrix& other);
	~Matrix();

	//Setters
	void setRows(const int rows);
	void setColomns(const int columns);
	void setPixels(const Pixel** pixels);

	//Getters
	int getRows() const;
	int getColomns() const;
	Pixel** getPixels() const;

	//friend ostream& operator<<(ostream& output, const Matrix& matrix);
	friend istream& operator>>(istream& input, Matrix& matrix);
};
