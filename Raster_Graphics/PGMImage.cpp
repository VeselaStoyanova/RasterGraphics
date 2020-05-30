#include <iostream>
#include "PGMImage.h"

using namespace std;

PGMImage::PGMImage(Matrix* matrix, string fileFormat, int maxColorValue, string name) :
	Image(matrix, fileFormat, maxColorValue, name)
{

}

ostream& PGMImage::outputImage(ostream& output) {
	output << fileFormat << endl;
	output << matrix->getColumns() << " ";
	output << matrix->getRows() << endl;
	output << maxColorValue << endl;

	for (int i = 0; i < matrix->getRows(); i++) {
		for (int j = 0; j < matrix->getColumns(); j++)
		{
			output << matrix->getPixels()[i][j].getRed() << " ";
		}
		output << endl;
	}

	return output;

}

void PGMImage::monochrome()
{
	for (int i = 0; i < matrix->getRows(); i++)
	{
		for (int j = 0; j < matrix->getColumns(); j++)
		{
			Pixel* pixel = &matrix->getPixels()[i][j];
			int r = pixel->getRed();
			int g = pixel->getGreen();
			int b = pixel->getBlue();

			int monochromeColor = (r + g + b) / 3;

			if (monochromeColor > 0 && monochromeColor <= maxColorValue / 2)
			{
				monochromeColor = 0;
				pixel->setRed(monochromeColor);
				pixel->setGreen(monochromeColor);
				pixel->setBlue(monochromeColor);
			}

			else if (monochromeColor > maxColorValue / 2 && monochromeColor <= maxColorValue)
			{
				monochromeColor = maxColorValue;
				pixel->setRed(monochromeColor);
				pixel->setGreen(monochromeColor);
				pixel->setBlue(monochromeColor);
			}

		}
	}
}