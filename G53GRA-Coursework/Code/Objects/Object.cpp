#include "Object.h"
#include "Services/Materials.h"
#include "Services/ExtraMaths.h"

Object::Object(ObjectModel* model)
{
	_model = model;
}

void Object::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);

	auto xRadians = degreesToRadians(rotation[0]);
	auto yRadians = degreesToRadians(rotation[1]);

	auto cosX = static_cast<GLfloat>(cos(xRadians));
	auto cosY = static_cast<GLfloat>(cos(yRadians));
	auto sinX = static_cast<GLfloat>(sin(xRadians));
	auto sinY = static_cast<GLfloat>(sin(yRadians));

	glRotatef(rotation[0], 1.0f, 0.f, 0.f);
	glRotatef(rotation[1], 0.0f, cosX, sinX);
	glRotatef(rotation[2], sinY * cosX, -sinX, cosY * cosX);

	glScalef(scale[0], scale[1], scale[2]);

	_model->Render();

	glPopAttrib();
	glPopMatrix();
}
