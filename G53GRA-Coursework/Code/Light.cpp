#include "Light.h"

Light::Light(GLenum lightNumber, float x, float y, float z)
{
	_lightNumber = lightNumber;
	position(x, y, z);
	size(10.f);

	SetAmbience(0.f, 0.f, 0.f, 1.f);
	SetDiffuse(0.f, 0.f, 0.f, 1.f);
	SetSpecular(0.f, 0.f, 0.f, 1.f);
	SetPosition(x, y, z);
	SetAsGlobalLight(false);
}

void Light::Display()
{
	glEnable(GL_LIGHTING);

	glLightfv(_lightNumber, GL_AMBIENT, _ambience);
	glLightfv(_lightNumber, GL_DIFFUSE, _diffuse);
	glLightfv(_lightNumber, GL_SPECULAR, _specular);
	glLightfv(_lightNumber, GL_POSITION, _position);
	if(!IsGlobalLight())
	{
		// TODO: This is really the general brightness of the light. It should be configurable
		glLightf(_lightNumber, GL_LINEAR_ATTENUATION, 0.01f);
	}
	glEnable(_lightNumber);

	// Draw a blob where the light is
	if (_drawOrb)
	{
		glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);

		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glColor4f(1.f, 0.75f, 0.f, 1.f);
		glTranslatef(pos[0], pos[1], pos[2]);
		glutSolidSphere(scale[0], 10.f, 10.f);

		glEnable(GL_LIGHTING);
		glPopAttrib();
		glPopMatrix();
	}
}

void Light::SetAmbience(float r, float g, float b, float a)
{
	_ambience[0] = r;
	_ambience[1] = g;
	_ambience[2] = b;
	_ambience[3] = a;
}

void Light::SetDiffuse(float r, float g, float b, float a)
{
	_diffuse[0] = r;
	_diffuse[1] = g;
	_diffuse[2] = b;
	_diffuse[3] = a;
}

void Light::SetSpecular(float r, float g, float b, float a)
{
	_specular[0] = r;
	_specular[1] = g;
	_specular[2] = b;
	_specular[3] = a;
}

void Light::SetPosition(float x, float y, float z)
{
	_position[0] = x;
	_position[1] = y;
	_position[2] = z;
}

void Light::SetAsGlobalLight(bool isGlobalLight)
{
	_position[3] = isGlobalLight ? 0.f : 1.f;
}

void Light::SetOrbDrawing(bool shouldDrawOrb)
{
	_drawOrb = shouldDrawOrb;
}

bool Light::IsGlobalLight() const
{
	return _position[3] == 0;
}
