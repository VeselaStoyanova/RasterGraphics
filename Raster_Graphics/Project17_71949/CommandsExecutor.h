#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Session.h"
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"
using namespace std;

void showHelp();
void showAdvancedHelp();
void showMenu();
string showStartMenu();
string showAdvancedMenu();

Matrix* constructMatrix(int rows, int columns, vector<int>numbers, string fileType);
Image* createImageWithMatrix(Matrix* matrix, string fileType, int maxColor, string filePath);
Image* loadFileWithImage(string filePath);

void saveImageInFile(Image& image, string filePath);
bool isCommandLoad(string choice);
bool isCommandSaveAs(string choice);
bool isCommandRotateLeft(string choice);
bool isCommandRotateRight(string choice);
bool isCommandAdd(string choice);
bool isCommandSessionInfo(string choice);
bool isCommandSwitchSession(string choice);
bool isCommandCollage(string choice);

string showParticularMenu(bool isFileLoad);