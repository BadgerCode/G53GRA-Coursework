#pragma once
#include "DisplayableObject.h"
#include "Objects/Object.h"

class Skybox : public DisplayableObject
{
public:
	Skybox();
	void Display() override;
private:
	Object* _skyboxObject;
};
