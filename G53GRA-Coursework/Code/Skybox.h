#pragma once
#include "DisplayableObject.h"

class Skybox : public DisplayableObject
{
public:
	Skybox(int sideLength, std::string filepath);
	void Display() override;
private:
	static void disableAllLights();
	static void enableAllLights();

	GLint _textureId;
	int _sideLength;
};
