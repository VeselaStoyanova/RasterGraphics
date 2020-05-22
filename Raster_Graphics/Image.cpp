#include <iostream>
#include "Image.h"

using namespace std;

void Image::copy(const Image& other)
{
	this->matrix = other.matrix;
	this->fileFormat = other.fileFormat;
	this->maxColourValue = other.maxColourValue;
}

void Image::erase()
{
	delete[] this->matrix;
}

Image::Image()
{
	this->matrix = 0;
	this->fileFormat = '/0';
	this->maxColourValue = 0;
}

Image::Image(Matrix* matrix, string fileFormat, const int maxColourValue)
{
	this->matrix = matrix;
	this->fileFormat = fileFormat;
	this->maxColourValue = maxColourValue;
}

Image::Image(const Image& other)
{
	this->copy(other);
	this->matrix = other.matrix;
	this->fileFormat = other.fileFormat;
	this->maxColourValue = other.maxColourValue;
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
		this->maxColourValue == other.maxColourValue;
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

void Image::setMaxColourValue(const int maxColourValue)
{
	this->maxColourValue = maxColourValue;
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

int Image::getMaxColourValue() const
{
	return this->maxColourValue;
}

ostream& operator<<(ostream& output, const Image& image)
{
	output << image.matrix << endl;
	output << image.fileFormat << endl;
	output << image.maxColourValue << endl;

	return output;
}

istream& operator>>(istream& input, Image& image)
{
	image.matrix = new Matrix();
	input >> *image.matrix;
	input >> image.fileFormat;
	input >> image.maxColourValue;

	return input;
}