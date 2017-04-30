#include "Skybox.h"

Skybox::Skybox(int sideLength, std::string filepath)
{
	_sideLength = sideLength;
	_textureId = Scene::GetTexture(filepath);
}

void Skybox::Display()
{
	auto halfSide = _sideLength / 2;

	glEnable(GL_LIGHTING);
	disableAllLights();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glColor4f(1.f, 1.f, 1.f, 1.f);

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

	enableAllLights();
}

void Skybox::disableAllLights()
{
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT3);
	glDisable(GL_LIGHT4);
	glDisable(GL_LIGHT5);
	glDisable(GL_LIGHT6);
	glDisable(GL_LIGHT7);
}

void Skybox::enableAllLights()
{
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glEnable(GL_LIGHT6);
	glEnable(GL_LIGHT7);
}
