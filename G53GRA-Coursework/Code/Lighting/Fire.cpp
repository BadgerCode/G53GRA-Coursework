#include "Fire.h"

Fire::Fire(float x, float y, float z): Light(x, y, z)
{
	_maxEmberY = pos[1] + 50.0f;
	_maxEmbers = 10;

	setupEmbers();
}

void Fire::setupEmbers()
{
	_embers.clear();
	for (auto i = 0; i < _maxEmbers; i++) {
		_embers.push_back(new Ember(pos, scale, _maxEmberY));
	}
}

void Fire::SetMaxEmbers(int maxEmbers)
{
	_maxEmbers = maxEmbers;
	setupEmbers();
}

void Fire::SetMaxEmberHeight(float maxHeight)
{
	_maxEmberY = pos[1] + maxHeight;
}

void Fire::SetEmberRadius(double emberRadius)
{
	for (auto ember : _embers)
	{
		ember->SetEmberRadius(emberRadius);
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
