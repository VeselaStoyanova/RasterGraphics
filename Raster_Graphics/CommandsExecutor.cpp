#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "CommandsExecutor.h"
#include "Image.h"
#include "Session.h"
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"
using namespace std;

void showHelp()
{
	cout << endl;
	cout << "The following commands are supported:" << endl;
	cout << "Load <path>		loads an existing file or creates a new file" << endl;
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

Matrix* constructMatrix(int rows, int columns, vector<int>numbers, string fileType)
{
	Matrix* matrix = nullptr;
	
		Pixel** pixels = new Pixel * [rows];

		for(int i = 0; i < rows; i++)
		{
			pixels[i] = new Pixel[columns];
		}

		int indexNumbers = 0;
		for (int i = 0; i < rows; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				if (fileType.compare("P3") == 0)
				{
					pixels[i][j] = Pixel(numbers[indexNumbers], numbers[indexNumbers + 1], numbers[indexNumbers + 2]);
					indexNumbers += 3;
				}

				else 
				{
					pixels[i][j] = Pixel(numbers[indexNumbers], numbers[indexNumbers], numbers[indexNumbers]);
					indexNumbers += 1;
				}
			}
		}

		/*for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << pixels[i][j];
			}
		}*/
	
	matrix = new Matrix(rows, columns, pixels);

	return matrix;
}

Image* createImageWithMatrix(Matrix* matrix, string fileType, int maxColor, string filePath)
{
	Image* image = nullptr;
	if (fileType.compare("P1") == 0)
	{
		image = new PBMImage(matrix, fileType, maxColor, filePath);
	}

	else if (fileType.compare("P2") == 0)
	{
		image = new PGMImage(matrix, fileType, maxColor, filePath);
	}

	else if (fileType.compare("P3") == 0)
	{
		image = new PPMImage(matrix, fileType, maxColor, filePath);
	}

	return image;
}

//Load file.
Image* loadFileWithImage(string filePath)
{
	ifstream inputFileStream;
	inputFileStream.open(filePath, ios::in);
	int maxColor = 1;
	string fileType;
	Matrix* matrix = nullptr;

	if (inputFileStream.is_open())
	{
		inputFileStream >> fileType;

		int columns;
		inputFileStream >> columns;
		int rows;
		inputFileStream >> rows;

		if (fileType.compare("P1") != 0)
		{
			inputFileStream >> maxColor;
		}

		int count = rows * columns;
		if (fileType.compare("P3") == 0)
		{
			count = count * 3;
		}

		vector<int>numbers;
		string currentNumberString;

		while (count > 0)
		{
			int currentNumber;
			inputFileStream >> currentNumber;
			numbers.push_back(currentNumber);
			count--;
		}

		matrix = constructMatrix(rows, columns, numbers, fileType);

	}

	else
	{
		cout << "The file " << filePath << " was not found." << endl;
	}

	return createImageWithMatrix(matrix, fileType, maxColor, filePath);
}

void saveImageInFile(Image& image, string filePath)
{
	ofstream outputFileStream;
	outputFileStream.open(filePath, ios::out);

	if (outputFileStream.is_open())
	{
		image.outputImage(outputFileStream);
	}
}

bool isCommandLoad(string choice)
{
	return choice.size() > 5 && choice.substr(0, 5).compare("load ") == 0;
}

bool isCommandSaveAs(string choice)
{
	return choice.size() > 8 && choice.substr(0, 8).compare("save as ") == 0;
}

bool isCommandRotate(string choice)
{
	return choice.size() > 7 && choice.substr(0, 7).compare("rotate ") == 0;
}

bool isCommandAdd(string choice)
{
	return choice.size() > 4 && choice.substr(0, 4).compare("add ") == 0;
}

bool isCommandSessionInfo(string choice)
{
	return choice.size() > 12 && choice.substr(0, 12).compare("session info") == 0;
}

bool isCommandSwitchSession(string choice)
{
	return choice.size() > 7 && choice.substr(0, 7).compare("switch ") == 0;
}

bool isCommandCollage(string choice)
{
	return choice.size() > 8 && choice.substr(0, 8).compare("collage ") == 0;
}

//Когато започваме ще можем да отворим файл, да видим какви команди поддържа програмата и да излезнем от програмата.
string showStartMenu()
{
	cout << "Enter one of the following options:" << endl;
	string choice;
	do
	{
		cout << "load <path to file>" << endl;
		cout << "help" << endl;
		cout << "exit" << endl;
		getline(cin, choice);
	}

	while (!isCommandLoad(choice) && choice.compare("help") != 0 && choice.compare("exit") != 0);

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
		cout << "grayscale" << endl;
		cout << "monochrome" << endl;
		cout << "negative" << endl;
		cout << "rotate <direction>" << endl;
		cout << "undo" << endl;
		cout << "add <image>" << endl;
		cout << "session info" << endl;
		cout << "switch <session>" << endl;
		cout << "collage <direction> <image1> <image2> <outimage>" << endl;
		getline(cin, choice);
	}

	while (choice.compare("close") != 0 && choice.compare("save") != 0 && !isCommandSaveAs(choice)
		&& choice.compare("help") != 0 && choice.compare("exit") != 0 && choice.compare("grayscale") != 0
		&& choice.compare("monochrome") != 0 && choice.compare("negative") != 0 && !isCommandRotate(choice)
		&& choice.compare("undo") != 0 && !isCommandAdd(choice) && !isCommandSessionInfo(choice)
		&& !isCommandSwitchSession(choice) && !isCommandCollage(choice));

	return choice;
}

string showParticularMenu(bool isFileLoad)
{
	if (!isFileLoad)
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
	bool isSessionStarted = false;
	vector<Session> sessions;
	string filePath;
	string choice;
	int sessionID = 1;

	while (choice.compare("exit") != 0)
	{
		choice = showParticularMenu(isSessionStarted);

		if (isCommandLoad(choice))
		{
			filePath = choice.substr(5, choice.size() - 5);

			//Проверяваме дали името на файла се състои само от интервали
			bool isFileNameNotOnlyIntervals = filePath.find_first_not_of(' ') != std::string::npos;
			if (isFileNameNotOnlyIntervals)
			{
				Session session = Session(sessionID);
				cout << "Session with ID: " << sessionID << " started" << endl;
				sessionID++;
				Image* image = loadFileWithImage(filePath);
				session.addImage(image);
				sessions.push_back(session);
				image->monochrome();
				saveImageInFile(*image, filePath);
				isSessionStarted = true;
			}

			else
			{
				cout << "Error, not a valid name!" << endl;
			}

		}

		else if (isSessionStarted == false && choice.compare("help") == 0)
		{
			showHelp();
		}

		else if (isSessionStarted == true && choice.compare("help") == 0)
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
			isSessionStarted = false;
		}

		else if (choice.compare("save") == 0)
		{
			//saveImageInFile(image, filePath);
			cout << "Successfully saved file." << endl;
			isSessionStarted = false;
		}

		else if (isCommandSaveAs(choice))
		{
			filePath = choice.substr(8, choice.size() - 8);
			//saveImageInFile(image, filePath);
			cout << "Successfully saved another file." << endl;
			isSessionStarted = false;
		}

		else if (choice.compare("help") == 0)
		{
			showAdvancedHelp();
		}

		else if (choice.compare("grayscale") == 0)
		{

		}

		else if (choice.compare("monochrome") == 0)
		{

		}

		else if (choice.compare("negative") == 0)
		{

		}

		else if (isCommandRotate(choice) == 0)
		{

		}

		else if (choice.compare("undo") == 0)
		{

		}

		else if (isCommandAdd(choice) == 0)
		{

		}

		else if (isCommandSessionInfo(choice) == 0)
		{

		}

		else if (isCommandSwitchSession(choice) == 0)
		{

		}

		else if (isCommandCollage(choice) == 0)
		{

 }

		else
		{
			cout << "Not a valid choice." << endl;
		}
	}
}
