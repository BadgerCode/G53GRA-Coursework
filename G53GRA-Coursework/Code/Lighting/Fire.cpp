#include "Fire.h"

const float Fire::MaxEmberHeight = 50.0f;
const int Fire::MaxEmbers = 10;

Fire::Fire(float x, float y, float z): Light(x, y, z)
{
	_maxEmberY = pos[1] + MaxEmberHeight;

	addEmbers();
}

void Fire::addEmbers()
{
	for (auto i = 0; i < MaxEmbers; i++) {
		_embers.push_back(new Ember(pos, scale, _maxEmberY));
	}
}

void Fire::Update(const double& deltaTime)
{
	for (auto ember : _embers)
	{
		ember->Update(deltaTime);
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
		if (ember->IsDisabled())
		{
			continue;
		}

		ember->Display();
	}

	glPopAttrib();
	glPopMatrix();
}
