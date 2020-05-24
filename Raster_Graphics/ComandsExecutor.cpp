﻿#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "ComandsExecutor.h"
#include "Image.h"
using namespace std;

void showHelp()
{
	cout << endl;
	cout << "The following commands are supported:" << endl;
	cout << "Open <path>		opens an existing file or creates a new file" << endl;
	cout << "Help			prints this information" << endl;
	cout << "Exit			exits the program" << endl;
	cout << endl;
}

void showAdvancedHelp()
{
	cout << endl;
	cout << "The following commands are supported: " << endl;
	cout << "Close			closes the currently opened file" << endl;
	cout << "Save			saves the currently open file" << endl;
	cout << "Save As			saves the currently open file in  <file>" << endl;
	cout << "Help			prints this information" << endl;
	cout << "Exit			exits the program" << endl;
	cout << endl;
}

//Open file.
void openFileWithImage(string filePath, Image& imageToFill)
{
	ifstream inputFileStream;
	inputFileStream.open(filePath, ios::in);

	if (inputFileStream.is_open())
	{
		inputFileStream >> imageToFill;
	}
}

void saveImageInFile(Image& image, string filePath)
{
	ofstream outputFileStream;
	outputFileStream.open(filePath, ios::out);

	if (outputFileStream.is_open())
	{
		outputFileStream << image;
	}
}

bool isCommandOpen(string choice)
{
	return choice.size() > 5 && choice.substr(0, 5).compare("open ") == 0;
}

bool isFileSavedAs(string choice)
{
	return choice.size() > 8 && choice.substr(0, 8).compare("save as ") == 0;
}

//Когато започваме ще можем да отворим файл, да видим какви команди поддържа програмата и да излезнем от програмата.
string showStartMenu()
{
	cout << "Enter one of the following options:" << endl;
	string choice;
	do
	{
		cout << "open <path to file>" << endl;
		cout << "help" << endl;
		cout << "exit" << endl;
		getline(cin, choice);
	}

	while (!isCommandOpen(choice) && choice.compare("help") != 0 && choice.compare("exit") != 0);

	return choice;
}

//Когато сме в даден файл ще можем да го затворим, да запишем промените във файла в същия файл,
//да запишем промените в друг файл, да видим какви команди поддържа програмата и да излезнем от програмата.
string showAdvancedMenu()
{
	cout << "Enter one of the following options: " << endl;
	string choice;

	do
	{
		cout << "close" << endl;
		cout << "save" << endl;
		cout << "save as" << endl;
		cout << "help" << endl;
		cout << "exit" << endl;
		getline(cin, choice);
	}

	while (choice.compare("close") != 0 && choice.compare("save") != 0 && !isFileSavedAs(choice)
		&& choice.compare("help") != 0 && choice.compare("exit") != 0);

	return choice;
}

string showParticularMenu(bool isFileOpen)
{
	if (!isFileOpen)
	{
		return showStartMenu();
	}

	else
	{
		return showAdvancedMenu();
	}
}

void showMenu()
{
	bool isFileOpen = false;
	Image image;
	string filePath;
	string choice;

	while (choice.compare("exit") != 0)
	{
		choice = showParticularMenu(isFileOpen);

		if (isCommandOpen(choice))
		{
			filePath = choice.substr(5, choice.size() - 5);

			//Проверяваме дали името на файла се състои само от интервали
			bool isFileNameOnlyIntervals = filePath.find_first_not_of(' ') != std::string::npos;
			if (isFileNameOnlyIntervals)
			{
				cout << "Open file." << endl;
				openFileWithImage(filePath, image);
				isFileOpen = true;
			}

			else
			{
				cout << "Error, not a valid name!" << endl;
			}

		}

		else if (isFileOpen == false && choice.compare("help") == 0)
		{
			showHelp();
		}

		else if (isFileOpen == true && choice.compare("help") == 0)
		{
			showAdvancedHelp();
		}

		else if (choice.compare("exit") == 0)
		{
			cout << "Exiting the program..." << endl;
		}

		else if (choice.compare("close") == 0)
		{
			cout << "Successfully closed file." << endl;
			isFileOpen = false;
		}

		else if (choice.compare("save") == 0)
		{
			saveImageInFile(image, filePath);
			cout << "Successfully saved file." << endl;
			isFileOpen = false;
		}

		else if (isFileSavedAs(choice))
		{
			filePath = choice.substr(8, choice.size() - 8);
			saveImageInFile(image, filePath);
			cout << "Successfully saved another file." << endl;
			isFileOpen = false;
		}

		else if (choice.compare("help") == 0)
		{
			showAdvancedHelp();
		}

		else
		{
			cout << "Not a valid choice." << endl;
		}
	}
}
