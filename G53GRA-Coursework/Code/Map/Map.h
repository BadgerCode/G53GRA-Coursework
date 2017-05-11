#pragma once
#include "DisplayableObject.h"
#include "Skybox.h"
#include "Lighting/Light.h"
#include "Animation.h"

class Map : public DisplayableObject, public Input, public Animation
{
public:
	explicit Map();
	void Display() override;

	void HandleKey(unsigned char key, int state, int x, int y) override;
	void HandleSpecialKey(int key, int state, int x, int y) override {};
	void HandleMouse(int button, int state, int x, int y) override {};
	void HandleMouseDrag(int x, int y) override {};
	void HandleMouseMove(int x, int y) override {};
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
	bool _debugEnableLighting = true;
};
