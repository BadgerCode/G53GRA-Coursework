#include "Lantern.h"

Lantern::Lantern( float x, float y, float z)
{
	_light = new Fire(x, y, z);
	_light->SetOrbDrawing(false);
	_light->SetAmbience(1.f, 1.f, 0.9f, 1.f);
	_light->SetDiffuse(1.f, 1.f, 0.5f, 1.f);
	_light->SetSpecular(1.f, 1.f, 1.f, 1.f);
	_light->SetDistance(150.f);
}

void Lantern::Display()
{
	_light->Display();
}
