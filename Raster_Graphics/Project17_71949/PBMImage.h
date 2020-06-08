#pragma once
#include <iostream>
#include "Image.h"

using namespace std;

class PBMImage : public Image
{

public:
	PBMImage(Matrix* matrix, string fileFormat, int maxColorValue, string name);
	ostream& outputImage(ostream& output);
};