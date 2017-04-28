#include "TestObject.h"
#include "Scene.h"

TestObject::TestObject()
{
	size(100);
	_textureId = Scene::GetTexture("./Textures/baked_beans_teaser.bmp");
}

void TestObject::Display()
{
	auto halfWidth = scale[0] / 2;
	auto halfHeight = scale[1] / 2;
	auto halfDepth = scale[2] / 2;

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	glBindTexture(GL_TEXTURE_2D, _textureId);

	glBegin(GL_TRIANGLES);
	{
		//glColor3f(1.f, 0.f, 0.f);

		// Front
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
		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glVertex3f(halfWidth, halfHeight, halfDepth);

		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glVertex3f(halfWidth, halfHeight, -halfDepth);
		glVertex3f(halfWidth, halfHeight, halfDepth);

		// Back
		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);
		glVertex3f(halfWidth, halfHeight, -halfDepth);

		glVertex3f(-halfWidth, -halfHeight, -halfDepth);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);
		glVertex3f(halfWidth, halfHeight, -halfDepth);

		// Left
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);
		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);

		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glVertex3f(-halfWidth, halfHeight, halfDepth);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);

		// Top
		glVertex3f(-halfWidth, halfHeight, halfDepth);
		glVertex3f(halfWidth, halfHeight, halfDepth);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);

		glVertex3f(halfWidth, halfHeight, halfDepth);
		glVertex3f(halfWidth, halfHeight, -halfDepth);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);

		// Bottom
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);
		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glVertex3f(halfWidth, -halfHeight, halfDepth);

		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);

	}
	glEnd();
}
