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

	void SetMaxEmbers(int maxEmbers);
	void SetMaxEmberHeight(float maxHeight);
	void SetEmberRadius(double emberRadius);
private:
	int _maxEmbers;
	float _maxEmberY;

	std::vector<Ember*> _embers;

	void setupEmbers();
};
