#pragma once
#include "DisplayableObject.h"
#include "Skybox.h"
#include "Objects/Light.h"

class Map : public DisplayableObject, public Input
{
public:
	explicit Map();
	void Display() override;

	void HandleKey(unsigned char key, int state, int x, int y) override;
	void HandleSpecialKey(int key, int state, int x, int y) override {};
	void HandleMouse(int button, int state, int x, int y) override {};
	void HandleMouseDrag(int x, int y) override {};
	void HandleMouseMove(int x, int y) override {};

private:
	Skybox* _skybox;
	Light* _sunlight;
	float _mapSize;

	void loadObjects();
	void setObjects(std::vector<DisplayableObject*> objects);
	DisplayableObject** _mapObjects;
	int _numObjects;

	float _lightLevel;
	bool _debugEnableLighting = true;
};
