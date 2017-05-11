#pragma once
#include "Objects/Object.h"
#include "Fire.h"

class Lantern : public Fire
{
public:
	Lantern(float x, float y, float z);
private:
	Object* _model;
};
