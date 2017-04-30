#include "Flashlight.h"


Flashlight::Flashlight(GLenum lightNumber): Light(lightNumber, 0, 0, 0)
{
	SetOrbDrawing(false);
}

void Flashlight::Update(const double& deltaTime)
{
	float& x = pos[0];
	float& y = pos[1];
	float& z = pos[2];
	Scene::GetCamera()->GetEyePosition(x, y, z);

	SetPosition(x, y, z);
}
