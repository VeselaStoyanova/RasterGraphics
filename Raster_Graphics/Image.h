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
	string name;
	void copy(const Image& other);
	void erase();

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

	friend ostream& operator<<(ostream& output, const Image& image);
	friend istream& operator>>(istream& input, Image& image);

};
