#pragma once
#include <iostream>
#include "Image.h"


using namespace std;

void showHelp();
void showAdvancedHelp();
//void openFileWithImage(string filePath, Image& imageToFill);
Image loadFileWithImage(string filePath);