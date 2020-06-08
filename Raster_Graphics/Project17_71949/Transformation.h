#pragma once
#include <iostream>

using namespace std;

enum Transformation
{
	GRAYSCALE,
	MONOCHROME,
	NEGATIVE,
	ROTATE_LEFT,
	ROTATE_RIGHT
};

ostream& operator<<(ostream& output, Transformation transformation);
