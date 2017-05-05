#include "Lantern.h"

Lantern::Lantern(GLenum lightNumber, float x, float y, float z)
{
	_light = new Light(lightNumber, x, y, z);
	_light->SetAmbience(0.75f, 0.75f, 0.65f, 1.f);
	_light->SetDiffuse(0.8f, 0.8f, 0.6f, 1.f);
	_light->SetSpecular(1.f, 1.f, 1.f, 1.f);
	_light->SetDistance(50.f);
}

void Lantern::Display()
{
	_light->Display();
}
