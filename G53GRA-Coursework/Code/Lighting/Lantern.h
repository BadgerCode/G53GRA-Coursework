#pragma once
#include "Objects/Object.h"
#include "Fire.h"

class Lantern : public DisplayableObject
{
public:
	Lantern(float x, float y, float z);

	void Display() override;
private:
	Fire* _light;
	Object* _model;
};
