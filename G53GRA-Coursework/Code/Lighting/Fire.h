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
	double _elapsedTimeSecs;

	static const double EmberRadius;
	static const float EmberVerticalSpeed;
	static const float EmberHorizontalSpeed;
	static const float MaxEmberHeight;
	static const int MaxEmbers;

	float _maxEmberY;
	std::vector<float*> _emberPositions;
	std::vector<Ember*> _embers;
	double _nextEmberTime;

	void addEmbers();
};
