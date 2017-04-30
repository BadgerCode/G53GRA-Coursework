#include "Map.h"

Map::Map()
{
	_mapSize = 5000;
	_skybox = new Skybox(5000, "./Textures/skybox.bmp");

	auto lightLevel = -0.35f;

	_sunlight = new Light(GL_LIGHT0, 2500.f, 2500.f, -2500.f);
	_sunlight->SetAsGlobalLight(true);
	_sunlight->SetAmbience(lightLevel, lightLevel, lightLevel, 1.f);
	_sunlight->SetDiffuse(0.f, 0.f, 0.f, 1.f);
	_sunlight->SetSpecular(0.f, 0.f, 0.f, 1.f);
}

void Map::Display()
{
	_skybox->Display();
	_sunlight->Display();
}
