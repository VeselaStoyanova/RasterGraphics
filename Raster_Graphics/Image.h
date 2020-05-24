#pragma once
#include <iostream>
#include "Matrix.h"
using namespace std;

class Image
{
private:
	Matrix* matrix;
	string fileFormat;
	int maxColourValue;
	void copy(const Image& other);
	void erase();

public:
	Image();
	Image(Matrix* matrix, string fileFormat, int maxColourValue);
	Image(const Image& other);
	Image& operator=(const Image& other);
	bool operator==(const Image& other);
	~Image();

	//Setters
	void setMatrix(Matrix* matrix);
	void setFileFormat(string fileFormat);
	void setMaxColourValue(const int maxColourValue);

	//Getters
	Matrix* getMatrix() const;
	string getFileFormat() const;
	int getMaxColourValue() const;

	friend ostream& operator<<(ostream& output, const Image& image);
	friend istream& operator>>(istream& input, Image& image);

};
