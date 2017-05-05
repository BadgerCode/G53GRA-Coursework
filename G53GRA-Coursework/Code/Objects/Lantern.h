#pragma once
#include "Light.h"
#include "Object.h"

class Lantern : public DisplayableObject
{
public:
	Lantern(GLenum lightNumber, float x, float y, float z);

	void Display() override;
private:
	Light* _light;
	Object* _model;
};
