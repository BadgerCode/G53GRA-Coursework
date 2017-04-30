#pragma once
#include "DisplayableObject.h"
#include "Light.h"
#include "Skybox.h"

class Map : public DisplayableObject
{
public:
	explicit Map();
	void Display() override;
private:
	Skybox* _skybox;
	Light* _sunlight;
	float _mapSize;
	GLint _floorTextureId;

	void RenderFloor();
};
