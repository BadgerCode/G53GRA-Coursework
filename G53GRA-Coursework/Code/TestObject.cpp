#include "TestObject.h"
#include "Scene.h"

TestObject::TestObject(float x, float y, float z)
{
	size(100);
	position(x, y, z);
	_textureId = Scene::GetTexture("./Textures/baked_beans_teaser.bmp");
}

void TestObject::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glTranslatef(pos[0], pos[1], pos[2]);

	auto halfWidth = scale[0] / 2;
	auto halfHeight = scale[1] / 2;
	auto halfDepth = scale[2] / 2;

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	glBindTexture(GL_TEXTURE_2D, _textureId);

	glBegin(GL_TRIANGLES);
	{
		glColor4f(1, 1, 1, 1.0f);

		// Front
		glNormal3f(0.f, 0.f, 1.f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-halfWidth, halfHeight, halfDepth);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(halfWidth, halfHeight, halfDepth);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-halfWidth, halfHeight, halfDepth);

		// Right
		glNormal3f(1.f, 0.f, 0.f);
		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glVertex3f(halfWidth, halfHeight, halfDepth);

		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glVertex3f(halfWidth, halfHeight, -halfDepth);
		glVertex3f(halfWidth, halfHeight, halfDepth);

		// Back
		glNormal3f(0.f, 0.f, -1.f);
		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);
		glVertex3f(halfWidth, halfHeight, -halfDepth);

		glVertex3f(-halfWidth, -halfHeight, -halfDepth);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);
		glVertex3f(halfWidth, halfHeight, -halfDepth);

		// Left
		glNormal3f(-1.f, 0.f, 0.f);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);
		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);

		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glVertex3f(-halfWidth, halfHeight, halfDepth);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);

		// Top
		glNormal3f(0.f, 1.f, 0.f);
		glVertex3f(-halfWidth, halfHeight, halfDepth);
		glVertex3f(halfWidth, halfHeight, halfDepth);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);

		glVertex3f(halfWidth, halfHeight, halfDepth);
		glVertex3f(halfWidth, halfHeight, -halfDepth);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);

		// Bottom
		glNormal3f(0.f, -1.f, 0.f);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);
		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glVertex3f(halfWidth, -halfHeight, halfDepth);

		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);

	}
	glEnd();
	glPopAttrib();
	glPopMatrix();
}
