#include "Fire.h"

const double Fire::EmberRadius = 0.75;
const float Fire::EmberVerticalSpeed = 20.0f;
const float Fire::EmberHorizontalSpeed = 10.0f;
const float Fire::MaxEmberHeight = 50.0f;
const int Fire::MaxEmbers = 10;

Fire::Fire(float x, float y, float z): Light(x, y, z)
{
	addEmbers();

	_elapsedTimeSecs = 0.f;
	_nextEmberTime = 0.f;

	_maxEmberY = pos[1] + MaxEmberHeight;
}

void Fire::addEmbers()
{
	for (auto i = 0; i < MaxEmbers; i++) {
		_embers.push_back(new Ember(pos, scale, _elapsedTimeSecs));
	}
}

void Fire::Update(const double& deltaTime)
{
	_elapsedTimeSecs += deltaTime;

	auto offset = sin(_elapsedTimeSecs * EmberHorizontalSpeed) / 100;

	for (auto ember : _embers)
	{
		if(ember->IsDisabled(_elapsedTimeSecs))
		{
			continue;
		}

		ember->Position[0] += offset;
		ember->Position[1] += static_cast<float>(deltaTime) * EmberVerticalSpeed;

		if(ember->Position[1] > _maxEmberY)
		{
			ember->Randomise(_elapsedTimeSecs);
		}
	}
}

void Fire::Display()
{
	Light::Display();

	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);


	glDisable(GL_LIGHTING);
	for (auto ember : _embers)
	{
		if (ember->IsDisabled(_elapsedTimeSecs))
		{
			continue;
		}

		ember->Display();
	}

	glPopAttrib();
	glPopMatrix();
}
