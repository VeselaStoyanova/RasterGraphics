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

Pixel& Pixel::operator=(const Pixel& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}

	return *this;
}

ostream& operator<<(ostream& output, const Pixel& pixels)
{
	output << pixels.red << endl;
	output << pixels.green << endl;
	output << pixels.blue << endl;
}

istream& operator>>(istream& input, Pixel& pixels)
{
	input >> pixels.red;
	input >> pixels.green;
	input >> pixels.blue;
}