#pragma once
#include <iostream>
#include "Image.h"
using namespace std;

class PGMImage : public Image
{
public:
	PGMImage(Matrix* matrix, string fileFormat, int maxColourValue, string name);
	ostream& outputImage(ostream& output);
};