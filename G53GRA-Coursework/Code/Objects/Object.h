#pragma once
#include "DisplayableObject.h"
#include "Objects/ObjectLoader.h"

class Object : public DisplayableObject
{
public:
	Object(const std::string& objectName, const std::string& customMaterial = "");

	void Display() override;
private:
	ObjectModel* _model;
};
