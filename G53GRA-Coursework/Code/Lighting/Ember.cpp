#include "Ember.h"
#include <cstdlib>

const float Ember::EmberVerticalSpeed = 20.0f;
const float Ember::EmberHorizontalSpeed = 10.0f;

Ember::Ember(float* startPosition, float* spawnArea, float maxEmberY)
{
	_startPosition = startPosition;
	_spawnArea = spawnArea;
	_maxEmberY = maxEmberY;
	_emberRadius = 0.75f;

	Colour = new float[4]{};
	Position = new float[3]{};

	_elapsedTimeSecs = 0.f;

	Randomise();
}

void Ember::Display()
{
	glPushMatrix();
	{
		glTranslatef(Position[0], Position[1], Position[2]);
		glColor4f(Colour[0], Colour[1], Colour[2], Colour[3]);
		glutSolidSphere(_emberRadius, 5, 5);
	}
	glPopMatrix();
}

void Ember::Update(const double& deltaTime)
{
	_elapsedTimeSecs += deltaTime;

	if (!_isDisabled) {
		Position[0] += static_cast<float>(sin((_elapsedTimeSecs - _nextEnableTimeSecs) * EmberHorizontalSpeed)) / 100;
		Position[1] += static_cast<float>(deltaTime) * EmberVerticalSpeed;

		if (Position[1] > _maxEmberY)
		{
			Randomise();
		}
	}

	_isDisabled = _elapsedTimeSecs < _nextEnableTimeSecs;
}

void Ember::Randomise()
{
	Colour[0] = static_cast<float>(100 - rand() % 15) / 100.f;
	Colour[1] = static_cast<float>(rand() % 50 + 1) / 100.f;
	Colour[2] = 0.0f;
	Colour[3] = 1.0f;

	Position[0] = getRandomPosition(_startPosition[0], _spawnArea[0] / 2);
	Position[1] = getRandomPosition(_startPosition[1], _spawnArea[1] / 2);
	Position[2] = getRandomPosition(_startPosition[2], _spawnArea[2] / 2);

	_nextEnableTimeSecs = _elapsedTimeSecs + rand() % 1000 / 100;
}

bool Ember::IsDisabled() const
{
	return _isDisabled;
}

void Ember::SetEmberRadius(double emberRadius)
{
	_emberRadius = emberRadius;
}

float Ember::getRandomPosition(float startPosition, float maxOffset)
{
	auto maxRand = static_cast<int>(maxOffset) * 2 * 1000;
	auto randOffset = maxOffset * 1000;
	return startPosition + (static_cast<float>(rand() % maxRand) - randOffset) / 1000.f;
}
