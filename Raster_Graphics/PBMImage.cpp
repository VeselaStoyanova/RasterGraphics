#include <iostream>
#include "PBMImage.h"

using namespace std;

PBMImage::PBMImage(Matrix* matrix, string fileFormat, int maxColorValue, string name):
		Image(matrix,fileFormat,maxColorValue,name)
{
}

ostream& PBMImage::outputImage(ostream& output)
{
	output << fileFormat << endl;
	output << matrix->getColumns() << " ";
	output << matrix->getRows() << endl;

	for (int i = 0; i < matrix->getRows(); i++)
	{
		for (int j = 0; j < matrix->getColumns(); j++)
		{
			output << matrix->getPixels()[i][j].getRed() << " ";
		}
		output << endl;
	}

	return output;
	
}