#include <iostream>
#include "PPMImage.h"

using namespace std;

PPMImage::PPMImage(Matrix* matrix, string fileFormat, int maxColorValue, string name) :
	Image(matrix, fileFormat, maxColorValue, name)
{

}

void PPMImage::grayscale()
{
	for (int i = 0; i < matrix->getRows(); i++)
	{
		for (int j = 0; j < matrix->getColumns(); j++)
		{
			Pixel* pixel = &matrix->getPixels()[i][j];
			int r = pixel->getRed();
			int g = pixel->getGreen();
			int b = pixel->getBlue();

			if (!(r == g && r == b))
			{
				int grayscaleColor = 0.30 * r + 0.59 * g + 0.11 * b;
				pixel->setRed(grayscaleColor);
				pixel->setGreen(grayscaleColor);
				pixel->setBlue(grayscaleColor);
			}
		}
	}
}

ostream& PPMImage::outputImage(ostream& output)
{
		output << fileFormat << endl;
		output << matrix->getColumns() << " ";
		output << matrix->getRows() << endl;
		output << maxColorValue << endl;

		for (int i = 0; i < matrix->getRows(); i++) 
		{
			for (int j = 0; j < matrix->getColumns(); j++)
			{
				output << matrix->getPixels()[i][j].getRed() << " ";
				output << matrix->getPixels()[i][j].getGreen() << " ";
				output << matrix->getPixels()[i][j].getBlue() << " ";
			}
			output << endl;
		}

		return output;
}

void PPMImage::monochrome()
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