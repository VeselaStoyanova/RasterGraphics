#include <iostream>
#include "PPMImage.h"

using namespace std;

PPMImage::PPMImage(Matrix* matrix, string fileFormat, int maxColourValue, string name) :
	Image(matrix, fileFormat, maxColourValue, name)
{

}

void PPMImage::grayscale()
{
	for (int i = 0; i < matrix->getRows(); i++)
	{
		for (int j = 0; j < matrix->getColomns(); j++)
		{
			Pixel* pixel = &matrix->getPixels()[i][j];
			int r = pixel->getRed();
			int g = pixel->getGreen();
			int b = pixel->getBlue();

			if (!(r == g && r == b))
			{
				int grayscaleColor = (r + g + b) / 3;
				pixel->setRed(grayscaleColor);
				pixel->setGreen(grayscaleColor);
				pixel->setBlue(grayscaleColor);
			}
		}
	}
}

ostream& PPMImage::outputImage(ostream& output) {
		output << fileFormat << endl;
		output << matrix->getColomns() << " ";
		output << matrix->getRows() << endl;
		output << maxColourValue << endl;

		for (int i = 0; i < matrix->getRows(); i++) {
			for (int j = 0; j < matrix->getColomns(); j++)
			{
				output << matrix->getPixels()[i][j].getRed() << " ";
				output << matrix->getPixels()[i][j].getGreen() << " ";
				output << matrix->getPixels()[i][j].getBlue() << " ";
			}
			output << endl;
		}

		return output;
}