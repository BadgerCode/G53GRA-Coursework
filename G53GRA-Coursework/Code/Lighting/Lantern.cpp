#include "Lantern.h"

Lantern::Lantern( float x, float y, float z) : Fire(x, y, z)
{
	SetOrbDrawing(false);
	SetAmbience(1.f, 1.f, 0.9f, 1.f);
	SetDiffuse(1.f, 1.f, 0.5f, 1.f);
	SetSpecular(1.f, 1.f, 1.f, 1.f);
	SetDistance(150.f);

	SetMaxEmberHeight(10.f);
	SetMaxEmbers(3);
	SetEmberRadius(0.25);
}
