#pragma once
#include "Animation.h"
#include "Objects/Light.h"

class Flashlight : public Light, public Animation
{
public:
	Flashlight(GLenum lightNumber);

	void Update(const double& deltaTime) override;
};
