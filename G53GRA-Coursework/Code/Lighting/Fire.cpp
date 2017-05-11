#include "Fire.h"

const double Fire::EmberRadius = 0.75;
const float Fire::EmberSpeed = 3.0;

Fire::Fire(float x, float y, float z): Light(x, y, z)
{
	_emberPositions.push_back(new float[3]{ pos[0], pos[1], pos[2] + 10.f });
}

void Fire::Update(const double& deltaTime)
{
	for (auto emberPosition : _emberPositions)
	{
		emberPosition[1] += static_cast<float>(deltaTime) * EmberSpeed;
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
