#pragma once
#include <iostream>
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
	void setColumns(const int columns);
	void setPixels(const Pixel** pixels);

	//Getters
	int getRows() const;
	int getColumns() const;
	Pixel** getPixels() const;

	friend istream& operator>>(istream& input, Matrix& matrix);
};