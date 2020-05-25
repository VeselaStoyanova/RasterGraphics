#include <iostream>
#include "Matrix.h"

using namespace std;

void Matrix::copy(const Matrix& other)
{
	this->rows = other.rows;
	this->columns = other.columns;
	
	this->pixels = new Pixel* [rows];
	for (int i = 0; i < rows; ++i)
	{
		this->pixels[i] = new Pixel[columns];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
		{
			this->pixels[i][j] = other.pixels[i][j];
		}
	}
}

void Matrix::erase()
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] this->pixels[i];
	}

	delete[] pixels;
}

Matrix::Matrix()
{
	this->rows = 0;
	this->columns = 0;
	this->pixels = nullptr;
}

Matrix::Matrix(int rows, int columns, Pixel** pixels)
{
	this->rows = rows;
	this->columns = columns;
	
	// Заделяме необходимата памет
	this->pixels = new Pixel* [rows];
	for (int i = 0; i < rows; ++i) 
	{
		this->pixels[i] = new Pixel[columns];
	}

	// Копираме самите стойности
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
		{
			this->pixels[i][j] = pixels[i][j];
		}
	}
}

Matrix::Matrix(const Matrix& other)
{
	this->copy(other);
	this->rows = other.rows;
	this->columns = other.columns;

	this->pixels = new Pixel* [rows];
	for (int i = 0; i < rows; ++i) 
	{
		this->pixels[i] = new Pixel[columns];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			this->pixels[i][j] = other.pixels[i][j];
		}
	}
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}

	return *this;
}

bool Matrix::operator==(const Matrix& other)
{
	return this->rows == other.rows &&
		this->columns == other.columns&&
		this->pixels == other.pixels;
}

Matrix::~Matrix()
{
	this->erase();
}

//Setters
void Matrix::setRows(const int rows)
{
	this->rows = rows;
}

void Matrix::setColomns(const int columns)
{
	this->columns = columns;
}

void Matrix::setPixels(const Pixel **pixels)
{
	this->erase();

	this->pixels = new Pixel* [rows];
	for (int i = 0; i < rows; ++i)
	{
		this->pixels[i] = new Pixel[columns];
	}

	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < columns; j++)
		{
			this->pixels[i][j] = pixels[i][j];
		}
	}

}

//Getters
int Matrix::getRows() const
{
	return this->rows;
}

int Matrix::getColomns() const
{
	return this->columns;
}

Pixel** Matrix::getPixels() const
{
	return this->pixels;
}

ostream& operator<<(ostream& output, const Matrix& matrix)
{
	output << matrix.rows << endl;
	output << matrix.columns << endl;

	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.columns; j++)
		{
			output << matrix.pixels[i][j] << " ";
		}
		output << endl;
	}
	
	return output;
}

istream& operator>>(istream& input, Matrix& matrix)
{
	matrix.erase();

	input >> matrix.rows;
	input >> matrix.columns;

	matrix.pixels = new Pixel* [matrix.rows];
	for (int i = 0; i < matrix.rows; ++i)
	{
		matrix.pixels[i] = new Pixel[matrix.columns];
	}

	for (int i = 0; i < matrix.rows; i++)
	{
		for (int j = 0; j < matrix.columns; j++)
		{
			input >> matrix.pixels[i][j];
		}
	}
	return input;
}