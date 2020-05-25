#include <iostream>
#include "Image.h"

using namespace std;

void Image::copy(const Image& other)
{
	this->matrix = other.matrix;
	this->fileFormat = other.fileFormat;
	this->maxColourValue = other.maxColourValue;
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
	this->maxColourValue = 0;
	this->name = '/0';
}

Image::Image(Matrix* matrix, string fileFormat, int maxColourValue, string name)
{
	this->matrix = matrix;
	this->fileFormat = fileFormat;
	this->maxColourValue = maxColourValue;
	this->name = name;
}

Image::Image(const Image& other)
{
	this->copy(other);
	this->matrix = other.matrix;
	this->fileFormat = other.fileFormat;
	this->maxColourValue = other.maxColourValue;
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
		this->maxColourValue == other.maxColourValue &&
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

void Image::setMaxColourValue(const int maxColourValue)
{
	this->maxColourValue = maxColourValue;
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

int Image::getMaxColourValue() const
{
	return this->maxColourValue;
}

string Image::getName() const
{
	return this->name;
}

istream& operator>>(istream& input, Image& image)
{
	input >> image.fileFormat;
	input >> image.maxColourValue;
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