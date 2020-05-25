#pragma once
#include <iostream>
using namespace std;

class Pixel
{
private:
	int red;
	int green;
	int blue;
	void copy(const Pixel& other);
	void erase();

public:
	Pixel();
	Pixel(int red, int green, int blue);
	Pixel& operator=(const Pixel& other);

	void setRed(const int red);
	void setGreen(const int green);
	void setBlue(const int blue);

	int getRed() const;
	int getGreen() const;
	int getBlue() const;

	friend istream& operator>>(istream& input, Pixel& m);
};