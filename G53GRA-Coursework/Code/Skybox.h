#pragma once
#include "DisplayableObject.h"

class Skybox : public DisplayableObject
{
public:
	Skybox(int sideLength, std::string filepath);
	void Display() override;
private:
	GLint _textureId;
	int _sideLength;
	float _ambientLightLevel;
};
