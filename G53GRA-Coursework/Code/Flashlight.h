#pragma once
#include "Light.h"
#include "Animation.h"

class Flashlight : public Light, public Animation
{
public:
	Flashlight(GLenum lightNumber);

	void Update(const double& deltaTime) override;
};
