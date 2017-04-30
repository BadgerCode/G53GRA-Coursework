#pragma once

#include "DisplayableObject.h"

class TestObject : public DisplayableObject
{
public:
	TestObject(float x, float y, float z);
	void Display() override;
private:
	GLint _textureId;
};