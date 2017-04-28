#include "TestObject.h"

TestObject::TestObject()
{
	size(100);
}

void TestObject::Display()
{
	auto halfWidth = scale[0] / 2;
	auto halfHeight = scale[1] / 2;
	auto halfDepth = scale[2] / 2;

	glBegin(GL_TRIANGLES);
	{
		glColor3f(1.f, 0.f, 0.f);

		// Front
		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glVertex3f(-halfWidth, halfHeight, halfDepth);

		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glVertex3f(halfWidth, halfHeight, halfDepth);
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
		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);

		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);

	}
	glEnd();
}
