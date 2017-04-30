#pragma once
#include "DisplayableObject.h"

class Light : public DisplayableObject
{
public:
	Light(GLenum lightNumber, float x, float y, float z);
	void Display() override;
private:
	GLenum _lightNumber;
};
