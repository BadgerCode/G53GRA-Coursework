#include "Light.h"

Light::Light(GLenum lightNumber, float x, float y, float z)
{
	_lightNumber = lightNumber;
	position(x, y, z);
}

void Light::Display()
{
	glEnable(GL_LIGHTING);

	GLfloat ambience[] = { 0.f, 0.f, 0.f, 0.f };
	GLfloat diffuse[] = { 0.8f, 0.8f, 0.8f, 1.5f };
	GLfloat specular[] = { 1.f, 1.f, 1.f, 1.f };
	GLfloat position[] = { pos[0], pos[1], pos[2], 1.0f };

	glLightfv(_lightNumber, GL_AMBIENT, ambience);
	glLightfv(_lightNumber, GL_DIFFUSE, diffuse);
	glLightfv(_lightNumber, GL_SPECULAR, specular);
	glLightfv(_lightNumber, GL_POSITION, position);
	glEnable(_lightNumber);

	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glDisable(GL_LIGHTING);

	glColor4f(1, 1, 1, 1);
	glTranslatef(position[0], position[1], position[2]);
	glutSolidSphere(10.0, 10, 10);

	glEnable(GL_LIGHTING);
	glPopAttrib();
	glPopMatrix();
}
