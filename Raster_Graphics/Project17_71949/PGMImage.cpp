#include "PGMImage.h"

using namespace std;

PGMImage::PGMImage(Matrix* matrix, string fileFormat, int maxColorValue, string name) :
	Image(matrix, fileFormat, maxColorValue, name)
{

}

//За формат PBM няма значение кой цвят от клас Pixel ще вземем
//Тъй като представлява изображения само с черни, бели и сиви пиксели.
ostream& PGMImage::outputImage(ostream& output)
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
		}
		output << endl;
	}
	return output;
}

//Функцията monochrome преобразува изображението до такова, в което има само черни и бели пиксели.
//Разделяме пиксела на 2.
//Ако полученото число е в интервала [0, maxColorValue / 2], то пикселът става черен.
//Ако полученото число е в интервала (maxColorValue / 2, maxColorValue], то пикселът става бял.
void PGMImage::monochrome()
{
	for (int i = 0; i < matrix->getRows(); i++)
	{
		for (int j = 0; j < matrix->getColumns(); j++)
		{
			Pixel* pixel = &matrix->getPixels()[i][j];

			int monochromeColor = pixel->getRed();

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