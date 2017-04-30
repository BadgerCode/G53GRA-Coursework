#include "Skybox.h"

Skybox::Skybox(int size, std::string filepath): _sideLength(size)
{
	_textureId = Scene::GetTexture(filepath);
	_ambientLightLevel = -0.15f;
}

void Skybox::Display()
{
	auto halfSide = _sideLength / 2;

	glEnable(GL_LIGHTING);
	GLfloat ambience[] = { _ambientLightLevel, _ambientLightLevel, _ambientLightLevel, 1.f };
	GLfloat diffuse[] = { 0.f, 0.f, 0.f, 1.f };
	GLfloat specular[] = { 0.f, 0.f, 0.f, 1.f };
	GLfloat position[] = { 5000.0f, 5000.0f, -5000.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambience);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHT0);
	glDisable(GL_LIGHT1);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glBegin(GL_TRIANGLES);
	{
		auto third = static_cast<float>(1) / 3;
		// Front (locked -z)
		{
			float textureOrigin[] = { 0.25, third };
			float textureEnd[] = { 0.5, third * 2 };

			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(-halfSide, halfSide, -halfSide);
			glTexCoord2f(textureOrigin[0], textureOrigin[1]);
			glVertex3f(-halfSide, -halfSide, -halfSide);
			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(halfSide, -halfSide, -halfSide);

			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(halfSide, -halfSide, -halfSide);
			glTexCoord2f(textureEnd[0], textureEnd[1]);
			glVertex3f(halfSide, halfSide, -halfSide);
			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(-halfSide, halfSide, -halfSide);
		}

		// Right (locked +x)
		{
			float textureOrigin[] = { 0.5, third };
			float textureEnd[] = { 0.75, third * 2 };

			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(halfSide - 10, halfSide, -halfSide);
			glTexCoord2f(textureOrigin[0], textureOrigin[1]);
			glVertex3f(halfSide - 10, -halfSide, -halfSide);
			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(halfSide - 10, -halfSide, halfSide);

			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(halfSide - 10, -halfSide, halfSide);
			glTexCoord2f(textureEnd[0], textureEnd[1]);
			glVertex3f(halfSide - 10, halfSide, halfSide);
			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(halfSide - 10, halfSide, -halfSide);
		}

		// Back (locked +z)
		{
			float textureOrigin[] = { 0.75, third };
			float textureEnd[] = { 1, third * 2 };

			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(halfSide, halfSide, halfSide);
			glTexCoord2f(textureOrigin[0], textureOrigin[1]);
			glVertex3f(halfSide, -halfSide, halfSide);
			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(-halfSide, -halfSide, halfSide);

			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(-halfSide, -halfSide, halfSide);
			glTexCoord2f(textureEnd[0], textureEnd[1]);
			glVertex3f(-halfSide, halfSide, halfSide);
			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(halfSide, halfSide, halfSide);
		}

		// Left (locked -x)
		{
			float textureOrigin[] = { 0, third };
			float textureEnd[] = { 0.25, third * 2 };

			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(-halfSide + 10, halfSide, halfSide);
			glTexCoord2f(textureOrigin[0], textureOrigin[1]);
			glVertex3f(-halfSide + 10, -halfSide, halfSide);
			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(-halfSide + 10, -halfSide, -halfSide);

			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(-halfSide + 10, -halfSide, -halfSide);
			glTexCoord2f(textureEnd[0], textureEnd[1]);
			glVertex3f(-halfSide + 10, halfSide, -halfSide);
			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(-halfSide + 10, halfSide, halfSide);
		}

		// Top (locked +y)
		{
			float textureOrigin[] = { 0.25, third * 2 };
			float textureEnd[] = { 0.5, third * 3 };

			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(-halfSide, halfSide - 10, halfSide);
			glTexCoord2f(textureOrigin[0], textureOrigin[1]);
			glVertex3f(-halfSide, halfSide - 10, -halfSide);
			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(halfSide, halfSide - 10, -halfSide);

			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(halfSide, halfSide - 10, -halfSide);
			glTexCoord2f(textureEnd[0], textureEnd[1]);
			glVertex3f(halfSide, halfSide - 10, halfSide);
			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(-halfSide, halfSide - 10, halfSide);
		}

		// Bottom (locked -y)
		{
			float textureOrigin[] = { 0.25, 0 };
			float textureEnd[] = { 0.5, third };

			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(-halfSide, -halfSide + 10, -halfSide);
			glTexCoord2f(textureOrigin[0], textureOrigin[1]);
			glVertex3f(-halfSide, -halfSide + 10, halfSide);
			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(halfSide, -halfSide + 10, halfSide);

			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(halfSide, -halfSide + 10, halfSide);
			glTexCoord2f(textureEnd[0], textureEnd[1]);
			glVertex3f(halfSide, -halfSide + 10, -halfSide);
			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(-halfSide, -halfSide + 10, -halfSide);
		}

	}
	glEnd();

	{
		GLfloat ambience[] = { 0.f, 0.f, 0.f, 0.f };
		GLfloat diffuse[] = { 0.8f, 0.8f, 0.8f, 1.5f };
		GLfloat specular[] = { 1.f, 1.f, 1.f, 1.f };
		GLfloat position[] = { -75.0f, 0.f, 60.f, 1.0f };

		glLightfv(GL_LIGHT1, GL_AMBIENT, ambience);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
		glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
		glLightfv(GL_LIGHT1, GL_POSITION, position);
		glEnable(GL_LIGHT1);

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
}
