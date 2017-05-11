#pragma once
#include "Objects/Object.h"
#include "Fire.h"

class Lantern : public Light
{
public:
	Lantern(float x, float y, float z);
private:
	Object* _model;
};
