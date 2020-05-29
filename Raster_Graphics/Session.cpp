#include <iostream>
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

void Session::setImages(vector<Image>images)
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

vector<Image> Session::getImages()const
{
	return this->images;
}

vector<Transformation> Session::getTransformations() const
{
	return this->transformations;
}

void Session::addImage(Image* image)
{
	this->images.push_back(*image);
}

void Session::addTransformation(Transformation transformation)
{
	this->transformations.push_back(transformation);
}

void Session::removeTransformation()
{
	this->transformations.pop_back();
}