#pragma once
#include "DisplayableObject.h"
#include "Lighting/Light.h"
#include "Animation.h"
#include "Objects/Object.h"
#include "Skybox.h"

class Map : public DisplayableObject, public Animation
{
public:
	explicit Map();
	void Display() override;
	void Update(const double& deltaTime) override;

private:
	Skybox* _skybox;
	Light* _sunlight;
	float _mapSize;

	static void loadCollisionCubes();

	void loadObjects();
	DisplayableObject** _mapObjects;
	int _numObjects;

	std::vector<Animation*> _animatedObjects;
	
	void loadLights();
	Light** _mapLights;
	int _numLights;

	float _lightLevel;
};
