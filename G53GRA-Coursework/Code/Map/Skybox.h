#pragma once
#include "DisplayableObject.h"

class Skybox : public DisplayableObject
{
public:
	Skybox(float sideLength);
	void Display() override;
private:
	void RenderSide(float textureOriginX, float textureOriginY) const;
	static void disableAllLights();
	static void enableAllLights();

	int _material;
	float _halfSideLength;
	float _yOffset;
};
