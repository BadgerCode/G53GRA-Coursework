#include "Fire.h"

const double Fire::EmberRadius = 0.75;
const float Fire::EmberVerticalSpeed = 20.0f;
const float Fire::EmberHorizontalSpeed = 10.0f;
const float Fire::MaxEmberHeight = 50.0f;

Fire::Fire(float x, float y, float z): Light(x, y, z)
{
	_emberPositions.push_back(new float[3]{ pos[0], pos[1], pos[2] + 10.f });
	_emberPositions.push_back(new float[3]{ pos[0] - 17.5f, pos[1] + 50.5f, pos[2] + 10.f });
	_emberPositions.push_back(new float[3]{ pos[0] + 15.f, pos[1] + 35.f, pos[2] + 10.f });
	_elapsedTime = 0.f;

	_maxEmberY = pos[1] + MaxEmberHeight;
}

void Fire::Update(const double& deltaTime)
{
	_elapsedTime += deltaTime;

	auto offset = sin(_elapsedTime * EmberHorizontalSpeed) / 100;

	for (auto emberPosition : _emberPositions)
	{
		emberPosition[0] += offset;
		emberPosition[1] += static_cast<float>(deltaTime) * EmberVerticalSpeed;

		if(emberPosition[1] > _maxEmberY)
		{
			emberPosition[1] -= floor(emberPosition[1] / _maxEmberY) * _maxEmberY;
		}
	}
}

void Fire::Display()
{
	Light::Display();

	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glColor3f(1.0f, 0.f, 0.f);

	glDisable(GL_LIGHTING);
	for (auto emberPosition : _emberPositions)
	{
		glPushMatrix();
		{
			glTranslatef(emberPosition[0], emberPosition[1], emberPosition[2]);
			glutSolidSphere(EmberRadius, 5, 5);

		}
		glPopMatrix();
	}

	glPopAttrib();
	glPopMatrix();
}
