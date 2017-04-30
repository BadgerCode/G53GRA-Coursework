#pragma once
#include "DisplayableObject.h"

class Skybox : public DisplayableObject
{
public:
	Skybox(GLenum sunLightNumber, int sideLength, std::string filepath);
	void Display() override;
private:
	GLenum _sunLightNumber;
	static void disableAllLights();
	static void enableAllLights();

	GLint _textureId;
	int _sideLength;
	float _ambientLightLevel;
};
