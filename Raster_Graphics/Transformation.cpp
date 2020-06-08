#include "Transformation.h"

using namespace std;

ostream& operator<<(ostream& output, Transformation transformation)
{
	switch (transformation)
	{
	case Transformation::GRAYSCALE: output << "GRAYSCALE"; break;
	case Transformation::MONOCHROME: output << "MONOCHROME"; break;
	case Transformation::NEGATIVE: output << "NEGATIVE"; break;
	case Transformation::ROTATE_LEFT: output << "ROTATE_LEFT"; break;
	case Transformation::ROTATE_RIGHT: output << "ROTATE_RIGHT"; break;

	default: output << "Not a valid transformation"; break;
	}

	return output;
}