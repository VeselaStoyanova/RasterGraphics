#pragma once
#include <iostream>
#include "Matrix.h"
using namespace std;

class Image
{
private:
	void copy(const Image& other);
	void erase();

protected:
	Matrix* matrix;
	string fileFormat;
	int maxColourValue;
	string name;

public:
	Image();
	Image(Matrix* matrix, string fileFormat, int maxColourValue, string name);
	Image(const Image& other);
	Image& operator=(const Image& other);
	bool operator==(const Image& other);
	~Image();

	//Setters
	void setMatrix(Matrix* matrix);
	void setFileFormat(string fileFormat);
	void setMaxColourValue(const int maxColourValue);
	void setName(string name);

	//Getters
	Matrix* getMatrix() const;
	string getFileFormat() const;
	int getMaxColourValue() const;
	string getName() const;

	friend istream& operator>>(istream& input, Image& image);

	virtual void grayscale();
	virtual ostream& outputImage(ostream& output);
};
