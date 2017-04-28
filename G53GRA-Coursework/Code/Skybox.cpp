#include "Skybox.h"

Skybox::Skybox(int size, std::string filepath): _sideLength(size)
{
	_textureId = Scene::GetTexture(filepath);
}

void Skybox::Display()
{
	auto halfSide = _sideLength / 2;

	glEnable(GL_TEXTURE_2D);
//	glEnable(GL_COLOR_MATERIAL);

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
}
