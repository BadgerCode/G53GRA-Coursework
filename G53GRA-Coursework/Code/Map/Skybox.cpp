#include "Skybox.h"
#include "Services/Materials.h"
#include "Objects/ObjectLoader.h"

Skybox::Skybox()
{
	_skyboxObject = ObjectLoader::LoadObject("Skybox");
	_skyboxObject->position(0.f, 0.f, 0.f);
	_skyboxObject->size(100.f, 100.f, 100.f);
}

void Skybox::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glDisable(GL_LIGHTING);

	_skyboxObject->Display();

	glPopAttrib();
	glPopMatrix();
}