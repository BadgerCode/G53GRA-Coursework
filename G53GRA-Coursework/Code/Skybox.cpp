#include "Skybox.h"

Skybox::Skybox(int size, std::string filepath): _sideLength(size)
{
	_textureId = Scene::GetTexture(filepath);
}

void Skybox::Display()
{
	auto halfSide = _sideLength / 2;

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	glBindTexture(GL_TEXTURE_2D, _textureId);

	glBegin(GL_TRIANGLES);
	{
		// Front (locked -z)
		{
			float textureOrigin[] = { 0.25, 0.3333 };
			float textureEnd[] = { 0.5, 0.6666 };

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
			float textureOrigin[] = { 0.5, 0.3333 };
			float textureEnd[] = { 0.75, 0.6666 };

			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(halfSide, halfSide, -halfSide);
			glTexCoord2f(textureOrigin[0], textureOrigin[1]);
			glVertex3f(halfSide, -halfSide, -halfSide);
			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(halfSide, -halfSide, halfSide);

			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(halfSide, -halfSide, halfSide);
			glTexCoord2f(textureEnd[0], textureEnd[1]);
			glVertex3f(halfSide, halfSide, halfSide);
			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(halfSide, halfSide, -halfSide);
		}

		// Back (locked +z)
		{
			float textureOrigin[] = { 0.75, 0.3333 };
			float textureEnd[] = { 1, 0.6666 };

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
			float textureOrigin[] = { 0, 0.3333 };
			float textureEnd[] = { 0.25, 0.6666 };

			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(-halfSide, halfSide, halfSide);
			glTexCoord2f(textureOrigin[0], textureOrigin[1]);
			glVertex3f(-halfSide, -halfSide, halfSide);
			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(-halfSide, -halfSide, -halfSide);

			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(-halfSide, -halfSide, -halfSide);
			glTexCoord2f(textureEnd[0], textureEnd[1]);
			glVertex3f(-halfSide, halfSide, -halfSide);
			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(-halfSide, halfSide, halfSide);
		}

		// Top (locked +y)
		{
			float textureOrigin[] = { 0.25, 0.6666 };
			float textureEnd[] = { 0.5, 0.9999 };

			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(-halfSide, halfSide, halfSide);
			glTexCoord2f(textureOrigin[0], textureOrigin[1]);
			glVertex3f(-halfSide, halfSide, -halfSide);
			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(halfSide, halfSide, -halfSide);

			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(halfSide, halfSide, -halfSide);
			glTexCoord2f(textureEnd[0], textureEnd[1]);
			glVertex3f(halfSide, halfSide, halfSide);
			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(-halfSide, halfSide, halfSide);
		}

		// Bottom (locked -y)
		{
			float textureOrigin[] = { 0.25, 0 };
			float textureEnd[] = { 0.5, 0.3333 };

			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(-halfSide, -halfSide, -halfSide);
			glTexCoord2f(textureOrigin[0], textureOrigin[1]);
			glVertex3f(-halfSide, -halfSide, halfSide);
			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(halfSide, -halfSide, halfSide);

			glTexCoord2f(textureEnd[0], textureOrigin[1]);
			glVertex3f(halfSide, -halfSide, halfSide);
			glTexCoord2f(textureEnd[0], textureEnd[1]);
			glVertex3f(halfSide, -halfSide, -halfSide);
			glTexCoord2f(textureOrigin[0], textureEnd[1]);
			glVertex3f(-halfSide, -halfSide, -halfSide);
		}

	}
	glEnd();
}
