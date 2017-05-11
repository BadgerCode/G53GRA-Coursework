#pragma once
#include "DisplayableObject.h"

class Ember : public DisplayableObject
{
public:
	Ember(float* startPosition, float* spawnArea, double elapsedTimeSecs);
	void Display() override;

	float* Position;
	float* Colour;

	void Randomise(double elapsedTimeSecs);
	bool IsDisabled(double elapsedTime) const;
private:
	static const double EmberRadius;

	float* _startPosition;
	float* _spawnArea;
	double _nextEnableTimeSecs;

	static float getRandomPosition(float startPosition, float maxOffset);
};
