#pragma once

#include "DisplayableObject.h"

class Cube : public DisplayableObject
{
public:
	Cube(float x, float y, float z);
	void Display() override;

	void SetTexture(std::string texturePath);
	void SetColour(float r, float g, float b, float a);
private:
	GLint _textureId;
	GLfloat _colour[4];
	bool _usingTexture;
};