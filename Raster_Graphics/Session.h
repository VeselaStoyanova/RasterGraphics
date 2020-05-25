#pragma once
#include <iostream>
#include <vector>
#include "Image.h"
#include "Transformation.h"

using namespace std;
class Session
{
	int sessionID;
	vector<Image>images;
	vector<Transformation>transformations;
	Session(int sessionID);
	void addImage(Image image);
	void addTransformation(Transformation transformation);
	void removeTransformation();

	void setSessionID(const int sessionID);
	void setImages(vector<Image>images);
	void setTransformations(vector<Transformation>transformations);
	int getSessionID() const;
	vector<Image> getImages()const;
	vector<Transformation> getTransformations() const;
};