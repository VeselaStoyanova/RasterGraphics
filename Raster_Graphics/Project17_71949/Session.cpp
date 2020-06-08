#include "Session.h"

using namespace std;

Session::Session(int sessionID)
{
	this->sessionID = sessionID;
}

//Setters
void Session::setSessionID(const int sessionID)
{
	this->sessionID = sessionID;
}

void Session::setImages(vector<Image*>images)
{
	this->images = images;
}

void Session::setTransformations(vector<Transformation>transformations)
{
	this->transformations = transformations;
}

//Getters
int Session::getSessionID() const
{
	return this->sessionID;
}

vector<Image*> Session::getImages()const
{
	return this->images;
}

vector<Transformation> Session::getTransformations() const
{
	return this->transformations;
}

//Функция, която добавя изображение във вектора от изображения.
void Session::addImage(Image* image)
{
	this->images.push_back(image);
}

//Функция, която добавя трансформация във вектора от трансформации.
void Session::addTransformation(Transformation transformation)
{
	this->transformations.push_back(transformation);
}

//Функция, която премахва трансформация от вектора с трансформации.
//Използва се за функцията undo, която премахва последно направената трансформация.
void Session::removeTransformation()
{
	//Проверяваме дали векторът е празен и ако не е, тогава премахваме трансформация.
	if (!transformations.empty())
	{
		this->transformations.pop_back();
	}
}

void Session::print()
{
	cout << "The session ID is: " << sessionID << endl;
	cout << "The images are: " << endl;

	for (int i = 0; i < images.size(); i++)
	{
		cout << images[i]->getName() << endl;
	}

	cout << "The transformations are: " << endl;

	for (int i = 0; i < transformations.size(); i++)
	{
		cout << transformations[i] << endl;
	}
}

//Функция, която премахва всички направени трансформации.
void Session::removeAllTransformations()
{
	this->transformations.clear();
}