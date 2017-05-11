#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Ember : public DisplayableObject, public Animation
{
public:
	Ember(float* startPosition, float* spawnArea, float maxEmberY);
	void Display() override;
	void Update(const double& deltaTime) override;

	float* Position;
	float* Colour;

	void Randomise();
	bool IsDisabled() const;
	void SetEmberRadius(double emberRadius);
private:
	static const float EmberVerticalSpeed;
	static const float EmberHorizontalSpeed;

	float* _startPosition;
	float* _spawnArea;
	float _maxEmberY;
	double _emberRadius;

	double _nextEnableTimeSecs;
	double _elapsedTimeSecs;
	bool _isDisabled;

	static float getRandomPosition(float startPosition, float maxOffset);
};
