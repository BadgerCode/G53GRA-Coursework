#pragma once
#include "Light.h"
#include "Animation.h"
#include "Ember.h"

class Fire: public Light, public Animation
{
public:
	Fire(float x, float y, float z);
	void Update(const double& deltaTime) override;
	void Display() override;
private:
	static const float MaxEmberHeight;
	static const int MaxEmbers;

	float _maxEmberY;
	std::vector<float*> _emberPositions;
	std::vector<Ember*> _embers;

	void addEmbers();
};
