#include <iostream>
#include "Matrix.h"

using namespace std;

void Matrix::copy(const Matrix& other)
{
	this->rows = other.rows;
	this->columns = other.columns;
	
	this->pixels = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		this->pixels[i] = new int[columns];
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

Matrix::Matrix(int rows, int columns, int **pixels)
{
	this->rows = rows;
	this->columns = columns;
	
	// Заделяме необходимата памет
	this->pixels = new int* [rows];
	for (int i = 0; i < rows; ++i) 
	{
		this->pixels[i] = new int[columns];
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

	this->pixels = new int* [rows];
	for (int i = 0; i < rows; ++i) 
	{
		this->pixels[i] = new int[columns];
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
		this->columns == other.columns;
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

void Matrix::setPixels(const int **pixels)
{
	this->erase();

	this->pixels = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		this->pixels[i] = new int[columns];
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

int** Matrix::getPixels() const
{
	return this->pixels;
}

ostream& operator<<(ostream& output, const Matrix& m)
{
	output << m.rows << endl;
	output << m.columns << endl;

	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.columns; j++)
		{
			output << m.pixels[i][j] << " ";
		}
		output << endl;
	}
	//output << m.pixels << endl;
	
	return output;
}

istream& operator>>(istream& input, Matrix& m)
{
	m.erase();

	input >> m.rows;
	input >> m.columns;

	m.pixels = new int* [m.rows];
	for (int i = 0; i < m.rows; ++i)
	{
		m.pixels[i] = new int[m.columns];
	}

	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.columns; j++)
		{
			input >> m.pixels[i][j];
		}
	}
	return input;
}