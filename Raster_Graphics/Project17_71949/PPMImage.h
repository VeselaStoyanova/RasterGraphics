#pragma once
#include <iostream>
#include "Image.h"

using namespace std;

class PPMImage : public Image
{

public:
	PPMImage(Matrix* matrix, string fileFormat, int maxColorValue, string name);
	void grayscale();
	void monochrome();
	ostream& outputImage(ostream& output);
};