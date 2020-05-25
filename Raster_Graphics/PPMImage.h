#pragma once
#include <iostream>
#include "Image.h"
using namespace std;

class PPMImage : public Image
{
public:
	PPMImage(Matrix* matrix, string fileFormat, int maxColourValue, string name);
	void grayscale();
	ostream& outputImage(ostream& output);
};