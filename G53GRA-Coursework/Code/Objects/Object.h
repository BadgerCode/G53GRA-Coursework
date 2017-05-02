#pragma once
#include "DisplayableObject.h"
#include "Objects/ObjectLoader.h"

class Object : public DisplayableObject
{
public:
	Object(std::string objectName);
	void Display() override;
private:
	std::vector<ObjectFace*> _faces;
};
