#pragma once

#include "../Framework/Engine/Scene.h"

class MyScene :
	public Scene
{
public:
	MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight);
	~MyScene() {};
protected:
	void HandleKey(unsigned char key, int state, int x, int y) override;
private:
	void Initialise() override;
	void Projection() override;

	bool _flashlightEnabled = false;
	int _flashlightNumber;
	void AddFlashlight();
};