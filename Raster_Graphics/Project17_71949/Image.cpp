#include "Image.h"

using namespace std;

void Image::copy(const Image& other)
{
	this->matrix = other.matrix;
	this->fileFormat = other.fileFormat;
	this->maxColorValue = other.maxColorValue;
	this->name = other.name;
}

void Image::erase()
{
	delete this->matrix;
}

Image::Image()
{
	this->matrix = 0;
	this->fileFormat = '/0';
	this->maxColorValue = 0;
	this->name = '/0';
}

Image::Image(Matrix* matrix, string fileFormat, int maxColorValue, string name)
{
	this->matrix = matrix;
	this->fileFormat = fileFormat;
	this->maxColorValue = maxColorValue;
	this->name = name;
}

Image::Image(const Image& other)
{
	this->copy(other);
	this->matrix = other.matrix;
	this->fileFormat = other.fileFormat;
	this->maxColorValue = other.maxColorValue;
	this->name = other.name;
}

Image& Image::operator=(const Image& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}

	return *this;
}

bool Image::operator==(const Image& other)
{
	return this->matrix == other.matrix &&
		this->fileFormat == other.fileFormat &&
		this->maxColorValue == other.maxColorValue &&
		this-> name == other.name;
}

Image::~Image()
{
	this->erase();
}

//Setters
void Image::setMatrix(Matrix* matrix)
{
	delete[] this->matrix;
	*this->matrix = *matrix;
}

void Image::setFileFormat(string fileFormat)
{
	this->fileFormat = fileFormat;
}

void Image::setMaxColorValue(const int maxColorValue)
{
	this->maxColorValue = maxColorValue;
}

void Image::setName(string name)
{
	this->name = name;
}

//Getters
Matrix* Image::getMatrix() const
{
	return this->matrix;
}

string Image::getFileFormat() const
{
	return this->fileFormat;
}

int Image::getMaxColorValue() const
{
	return this->maxColorValue;
}

string Image::getName() const
{
	return this->name;
}

istream& operator>>(istream& input, Image& image)
{
	input >> image.fileFormat;
	input >> image.maxColorValue;
	image.matrix = new Matrix();
	input >> *image.matrix;
	input >> image.name;
	
	return input;
}

void Image::grayscale()
{

}

ostream& Image::outputImage(ostream& output)
{
	return output;
}

//Намирането на индексите на пикселите при функцията rotate left става като от броя на колоните извадим 1 и j 
//И колоните станат редове, а редовете колони.
void Image::rotateLeftImage()
{
	int rows = matrix->getColumns();
	int columns = matrix->getRows();
	Pixel** rotatedMatrixPixels = new Pixel* [rows];

	for (int i = 0; i < rows; ++i)
	{
		rotatedMatrixPixels[i] = new Pixel[columns];
	}

	for (int i = 0; i < matrix->getRows(); i++)
	{
		for (int j = 0; j < matrix->getColumns(); j++)
		{
			int newColumns = matrix->getColumns() - j - 1;
			rotatedMatrixPixels[newColumns][i] = matrix->getPixels()[i][j];
		}
	}
	
	delete matrix;
	matrix = new Matrix(rows, columns, rotatedMatrixPixels);
}

//Намирането на индексите на пикселите при функцията rotate right става като от броя на редовете извадим 1 и i 
//И колоните станат редове, а редовете колони.
void Image::rotateRightImage()
{
	int rows = matrix->getColumns();
	int columns = matrix->getRows();
	Pixel** rotatedMatrixPixels = new Pixel * [rows];

	for (int i = 0; i < rows; ++i)
	{
		rotatedMatrixPixels[i] = new Pixel[columns];
	}

	for (int i = 0; i < matrix->getRows(); i++)
	{
		for (int j = 0; j < matrix->getColumns(); j++)
		{
			int newRows = matrix->getRows() - 1 - i;
			rotatedMatrixPixels[j][newRows] = matrix->getPixels()[i][j];
		}
	}

	delete matrix;
	matrix = new Matrix(rows, columns, rotatedMatrixPixels);
}

//Функцията negativе променя цвета като от максималния възможен цвят изважда текущия.
void Image::negative()
{
	for (int i = 0; i < matrix->getRows(); i++)
	{
		for (int j = 0; j < matrix->getColumns(); j++)
		{
			Pixel* pixel = &matrix->getPixels()[i][j];
			int r = pixel->getRed();
			int g = pixel->getGreen();
			int b = pixel->getBlue();

			int negativeRed = maxColorValue - r;
			int negativeGreen = maxColorValue - g;
			int negativeBlue = maxColorValue - b;

			pixel->setRed(negativeRed);
			pixel->setGreen(negativeGreen);
			pixel->setBlue(negativeBlue);
		}
	}
}

void Image::monochrome()
{
	
}