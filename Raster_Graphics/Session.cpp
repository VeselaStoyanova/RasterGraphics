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

void Session::addImage(Image* image)
{
	this->images.push_back(image);
}

void Session::addTransformation(Transformation transformation)
{
	this->transformations.push_back(transformation);
}

void Session::removeTransformation()
{
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

void Session::removeAllTransformations()
{
	this->transformations.clear();
}