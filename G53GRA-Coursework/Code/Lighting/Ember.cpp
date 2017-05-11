#include "Ember.h"
#include <cstdlib>

const double Ember::EmberRadius = 0.75;

Ember::Ember(float* startPosition, float* spawnArea, double elapsedTimeSecs)
{
	_startPosition = startPosition;
	_spawnArea = spawnArea;

	Colour = new float[4]{};
	Position = new float[3]{};

	Randomise(elapsedTimeSecs);
}

void Ember::Display()
{
	glPushMatrix();
	{
		glTranslatef(Position[0], Position[1], Position[2]);
		glColor4f(Colour[0], Colour[1], Colour[2], Colour[3]);
		glutSolidSphere(EmberRadius, 5, 5);

	}
	glPopMatrix();
}

void Ember::Randomise(double elapsedTimeSecs)
{
	Colour[0] = static_cast<float>(100 - rand() % 15) / 100.f;
	Colour[1] = static_cast<float>(rand() % 50 + 1) / 100.f;
	Colour[2] = 0.0f;
	Colour[3] = 1.0f;

	Position[0] = getRandomPosition(_startPosition[0], _spawnArea[0] / 2);
	Position[1] = getRandomPosition(_startPosition[1], _spawnArea[1] / 2);
	Position[2] = getRandomPosition(_startPosition[2], _spawnArea[2] / 2);

	_nextEnableTimeSecs = elapsedTimeSecs + rand() % 1000 / 100;
}

bool Ember::IsDisabled(double elapsedTime) const
{
	return elapsedTime < _nextEnableTimeSecs;
}

float Ember::getRandomPosition(float startPosition, float maxOffset)
{
	auto maxRand = static_cast<int>(maxOffset) * 2 * 1000;
	auto randOffset = maxOffset * 1000;
	return startPosition + (static_cast<float>(rand() % maxRand) - randOffset) / 1000.f;
}
