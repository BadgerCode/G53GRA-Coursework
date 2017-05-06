#pragma once
#include "Animation.h"
#include "Light.h"

class Flashlight : public Light, public Animation
{
public:
	Flashlight();

	void Update(const double& deltaTime) override;
};
