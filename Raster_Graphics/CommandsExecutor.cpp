#include "CommandsExecutor.h"

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
	cout << "Grayscale		makes the color images grayscale" << endl;
	cout << "Monochrome		makes the color images black and white" << endl;
	cout << "Negative		makes the images negative" << endl;
	cout << "Rotate <direction>	rotate the image(left or right)" << endl;
	cout << "Undo			removes the last transformation" << endl;
	cout << "Add image		adds image to the current session" << endl;
	cout << "Session info		gives an information for the current session" << endl;
	cout << "Switch <session>	switches to another session" << endl;
	cout << "Collage <direction><image1><image2><outimage>	makes a collage from the images" << endl;
	cout << endl;
}

//Конструираме матрица.
//Задаваме брой на редове, брой на колони, числата в матрицата и типът на файла.
Matrix* constructMatrix(int rows, int columns, vector<int>numbers, string fileType)
{
	Matrix* matrix = nullptr;

	Pixel** pixels = new Pixel *[rows];

	for (int i = 0; i < rows; i++)
	{
		pixels[i] = new Pixel[columns];
	}

	int indexNumbers = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			//При "P3" на един пиксел отговарят 3 стойности, а при останалите 2 вида на един пиксел отговаря 1 стойност.
			//При конструирането на пиксел при "P3" използваме 3 числа като всяко отговаря съответно за red, green, blue.
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

	matrix = new Matrix(rows, columns, pixels);

	return matrix;
}

//Функция, чрез която създаваме изображение от матрица.
Image* createImageWithMatrix(Matrix* matrix, string fileType, int maxColor, string filePath)
{
	Image* image = nullptr;
	//Сравняваме типът на файла и създаваме съответния вид изображение.
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

//Функция, която зарежда файл.
Image* loadFileWithImage(string filePath)
{
	ifstream inputFileStream;
	inputFileStream.open(filePath, ios::in);
	int maxColor = 1;
	string fileType;
	Matrix* matrix = nullptr;

	if (inputFileStream.is_open())
	{
		//Въвеждаме типът на файла.
		inputFileStream >> fileType;

		int columns;
		//Въвеждаме броят на колоните.
		inputFileStream >> columns;
		int rows;
		//Въвеждаме броят на редовете.
		inputFileStream >> rows;

		//Само при файловият формат "P1" нямаме максимален цвят.
		if (fileType.compare("P1") != 0)
		{
			//Ако файловият формат е "Р2" или "Р3" то въвеждаме и максимален цвят.
			inputFileStream >> maxColor;
		}

		//Броят на числата в матрицата е борят на редовете * броят на колоните.
		int count = rows * columns;

		//Броят на числата в матрицата при файловия формат "Р3" са брой на редове * брой на колони * 3
		//Тъй като за всеки пиксел от матрицата отговарят по 3 стойности.
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

//Запазваме изображение във файл.
void saveImageInFile(Image& image, string filePath)
{
	ofstream outputFileStream;
	outputFileStream.open(filePath, ios::out);

	if (outputFileStream.is_open())
	{
		image.outputImage(outputFileStream);
	}
}

//Проверяваме дали въведената команда от потребителя е load като сравняваме string-а, който е въвел потребителя с load.
bool isCommandLoad(string choice)
{
	return choice.size() > 5 && choice.substr(0, 5).compare("load ") == 0;
}

//Проверяваме дали въведената команда от потребителя е save as.
bool isCommandSaveAs(string choice)
{
	return choice.size() > 8 && choice.substr(0, 8).compare("save as ") == 0;
}

//Проверяваме дали въведената команда от потребителя е rotate left.
bool isCommandRotateLeft(string choice)
{
	return choice.compare("rotate left") == 0;
}

//Проверяваме дали въведената команда от потребителя е rotate right.
bool isCommandRotateRight(string choice)
{
	return choice.compare("rotate right") == 0;
}
//Проверяваме дали въведената команда от потребителя е add.
bool isCommandAdd(string choice)
{
	return choice.size() > 4 && choice.substr(0, 4).compare("add ") == 0;
}

//Проверяваме дали въведената команда от потребителя e session info.
bool isCommandSessionInfo(string choice)
{
	return choice.compare("session info") == 0;
}

//Проверяваме дали въведената команда от потребителя е switch session.
bool isCommandSwitchSession(string choice)
{
	return choice.size() > 7 && choice.substr(0, 7).compare("switch ") == 0;
}

//Проверяваме дали въведената команда от потребителя е collage.
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
		cout << endl;
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
		cout << endl;
	}
	
	//Валидиране на въведената команда от потребителя.
	while (choice.compare("close") != 0 && choice.compare("save") != 0 && !isCommandSaveAs(choice)
		&& choice.compare("help") != 0 && choice.compare("exit") != 0 && choice.compare("grayscale") != 0
		&& choice.compare("monochrome") != 0 && choice.compare("negative") != 0 && !isCommandRotateLeft(choice)
		&& !isCommandRotateRight(choice) && choice.compare("undo") != 0 && !isCommandAdd(choice) && !isCommandSessionInfo(choice)
		&& !isCommandSwitchSession(choice) && !isCommandCollage(choice));

	return choice;
}

//Проверяваме дали имаме зареден файл.
//Ако нямаме, то отваряме първоначалното меню.
//Ако имаме, то отваряме advanced меню.
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

//Функция, чрез която добавяме трансформация към сесията.
void addTransformationToCurrentSession(vector <Session>& sessions, int currentSessionID, Transformation transformation)
{
	for (int i = 0; i < sessions.size(); i++)
	{
		//Ако идентификационният номер на сесията и сегашният идентификационен номер съвпадат, то фобавяме нова трансформация.
		if (currentSessionID == sessions[i].getSessionID())
		{
			sessions[i].addTransformation(transformation);
		}
	}
}

//Извършване на трансформацията.
void applyTranformationsToCurrentSession(vector <Session>& sessions, int currentSessionID, string firstFileName = "")
{
	for (int i = 0; i < sessions.size(); i++)
	{
		if (currentSessionID == sessions[i].getSessionID())
		{
			for (int j = 0; j < sessions[i].getImages().size(); j++)
			{
				for (int k = 0; k < sessions[i].getTransformations().size(); k++)
				{
					switch (sessions[i].getTransformations()[k])
					{
					case Transformation::GRAYSCALE: sessions[i].getImages()[j]->grayscale(); break;
					case Transformation::MONOCHROME: sessions[i].getImages()[j]->monochrome(); break;
					case Transformation::NEGATIVE: sessions[i].getImages()[j]->negative(); break;
					case Transformation::ROTATE_LEFT: sessions[i].getImages()[j]->rotateLeftImage(); break;
					case Transformation::ROTATE_RIGHT: sessions[i].getImages()[j]->rotateRightImage(); break;
					}
				}
				string filePath = sessions[i].getImages()[j]->getName();

				//Използваме тази функция за командите save и save as.
				//Ако имаме името на файла е различно от празен string, то значи командата ни е save as.
				if (j == 0 && firstFileName.compare("") != 0)
				{
					filePath = firstFileName;
				}

				saveImageInFile(*sessions[i].getImages()[j], filePath);
			}

			sessions[i].removeAllTransformations();
		}
	}
}

void showMenu()
{
	bool isSessionStarted = false;
	vector<Session> sessions;
	int currentSessionID = 0;
	string choice;
	int sessionID = 1;

	while (choice.compare("exit") != 0)
	{
		choice = showParticularMenu(isSessionStarted);

		if (isCommandLoad(choice))
		{
			string filePath = choice.substr(5, choice.size() - 5);

			//Проверяваме дали името на файла се състои само от интервали
			bool isFileNameNotOnlyIntervals = filePath.find_first_not_of(' ') != std::string::npos;
			if (isFileNameNotOnlyIntervals)
			{
				Session session = Session(sessionID);
				cout << "Session with ID: " << sessionID << " started" << endl;
				currentSessionID = sessionID;
				sessionID++;
				Image* image = loadFileWithImage(filePath);
				session.addImage(image);
				sessions.push_back(session);
				isSessionStarted = true;
			}

			//Приемаме, че име, състоящо се само от интервали, е невалидно.
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
			applyTranformationsToCurrentSession(sessions, currentSessionID);
			cout << "Successfully saved files in the session." << endl;
			isSessionStarted = false;
		}

		else if (isCommandSaveAs(choice))
		{
			string filePath = choice.substr(8, choice.size() - 8);
			applyTranformationsToCurrentSession(sessions, currentSessionID, filePath);
			cout << "Successfully saved files in the session and the first image is saved under path " << filePath << "." << endl;
			isSessionStarted = false;
		}

		else if (choice.compare("grayscale") == 0)
		{
			addTransformationToCurrentSession(sessions, currentSessionID, GRAYSCALE);
		}

		else if (choice.compare("monochrome") == 0)
		{
			addTransformationToCurrentSession(sessions, currentSessionID, MONOCHROME);
		}

		else if (choice.compare("negative") == 0)
		{
			addTransformationToCurrentSession(sessions, currentSessionID, NEGATIVE);
		}

		else if (isCommandRotateLeft(choice))
		{
			addTransformationToCurrentSession(sessions, currentSessionID, ROTATE_LEFT);
		}

		else if (isCommandRotateRight(choice))
		{
			addTransformationToCurrentSession(sessions, currentSessionID, ROTATE_RIGHT);
		}

		else if (choice.compare("undo") == 0)
		{
			//Проверяваме дали въведената команда е undo.
			//Ако е, то премахваме последната трансформация.
			for (int i = 0; i < sessions.size(); i++)
			{
				if (currentSessionID == sessions[i].getSessionID())
				{
					sessions[i].removeTransformation();
				}
			}
		}

		else if (isCommandAdd(choice))
		{
			string filePath = choice.substr(4, choice.size() - 4);

			//Проверяваме дали името на файла се състои само от интервали
			bool isFileNameNotOnlyIntervals = filePath.find_first_not_of(' ') != std::string::npos;
			if (isFileNameNotOnlyIntervals)
			{
				for (int i = 0; i < sessions.size(); i++)
				{
					if (currentSessionID == sessions[i].getSessionID())
					{
						Image* image = loadFileWithImage(filePath);
						sessions[i].addImage(image);
					}
				}
			}

			else
			{
				cout << "Error, not a valid name!" << endl;
			}
		}

		else if (isCommandSessionInfo(choice))
		{
		//Обхождаме векторът от сесии.
		//Извеждаме информация за сесията, в която се намираме.
			for (int i = 0; i < sessions.size(); i++)
			{
				if (currentSessionID == sessions[i].getSessionID())
				{
					sessions[i].print();
				}
			}
		}

		else if (isCommandSwitchSession(choice))
		{
			string newSessionIDString = choice.substr(7, choice.size() - 7);
			int newSessionID = stoi(newSessionIDString);
			bool wasSessionFound = false;
			//Обхождаме векторът от сесии.
			for (int i = 0; i < sessions.size(); i++)
			{
				if (newSessionID == sessions[i].getSessionID())
				{
					currentSessionID = newSessionID;
					wasSessionFound = true;
				}
			}

			//Ако не намерим сесия с въведения идентификационен номер, то се извежда съобщение за грешка.
			if (wasSessionFound == false)
			{
				cout << "The session with ID " << newSessionID << " was not found. " << endl;
			}
		}

		else if (isCommandCollage(choice))
		{
			cout << "Not supported." << endl;
		}

		else
		{
			cout << "Not a valid choice." << endl;
		}
	}
}
