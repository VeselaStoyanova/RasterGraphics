#include <iostream>
#include "PBMImage.h"

using namespace std;

PBMImage::PBMImage(Matrix* matrix, string fileFormat, int maxColourValue, string name):
		Image(matrix,fileFormat,maxColourValue,name)
{
}

ostream& PBMImage::outputImage(ostream& output) {
	output << fileFormat << endl;
	output << matrix->getColomns() << " ";
	output << matrix->getRows() << endl;

	for (int i = 0; i < matrix->getRows(); i++) {
		for (int j = 0; j < matrix->getColomns(); j++)
		{
			output << matrix->getPixels()[i][j].getRed() << " ";
		}
		output << endl;
	}

	return output;
	
}