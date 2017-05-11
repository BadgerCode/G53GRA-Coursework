#pragma once
#include "Light.h"
#include "Animation.h"

class Fire: public Light, public Animation
{
public:
	Fire(float x, float y, float z);
	void Update(const double& deltaTime) override;
	void Display() override;
private:
	static const double EmberRadius;
	static const float EmberSpeed;

	std::vector<float*> _emberPositions;
};
