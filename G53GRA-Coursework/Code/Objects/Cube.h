#pragma once

#include "DisplayableObject.h"

class Cube : public DisplayableObject
{
public:
	Cube(float centerPos[], float cubeSize[]);
	void Display() override;

	void SetTexture(std::string materialName);
	void SetTextureScale(float x, float y);
	void SetColour(float r, float g, float b, float a);
private:
	GLint _textureId;
	GLfloat _colour[4];
	bool _usingTexture;
	float _textureScale[2];
};
