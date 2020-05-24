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
	friend ostream& operator<<(ostream& output, const Pixel& m);
	friend istream& operator>>(istream& input, Pixel& m);
};