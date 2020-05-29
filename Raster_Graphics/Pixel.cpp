#include <iostream>
#include "Pixel.h"
using namespace std;

Pixel::Pixel()
{
	this->red = 0;
	this->green = 0;
	this->blue = 0;
}

Pixel::Pixel(int red, int green, int blue)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}

void Pixel::copy(const Pixel& other)
{
	this->red = other.red;
	this->green = other.green;
	this->blue = other.blue;
}

void Pixel::erase()
{

}

//Setters
void Pixel::setRed(const int red)
{
	this->red = red;
}

void Pixel::setGreen(const int green)
{
	this->green = green;
}

void Pixel::setBlue(const int blue)
{
	this->blue = blue;
}

//Getters
int Pixel::getRed() const
{
	return this->red;
}

int Pixel::getGreen() const
{
	return this->green;
}

int Pixel::getBlue() const
{
	return this->blue;
}

Pixel& Pixel::operator=(const Pixel& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}

	return *this;
}

istream& operator>>(istream& input, Pixel& pixels)
{
	input >> pixels.red;
	input >> pixels.green;
	input >> pixels.blue;

	return input;
}