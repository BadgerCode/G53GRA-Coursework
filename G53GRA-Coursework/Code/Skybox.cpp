#include "Skybox.h"

Skybox::Skybox(float sideLength, std::string filepath)
{
	_halfSideLength = sideLength / 2.f;
	_textureId = Scene::GetTexture(filepath);

	_yOffset = 2.f * _halfSideLength / 3.f;
}

void Skybox::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glDisable(GL_LIGHTING);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);
	glColor4f(1.f, 1.f, 1.f, 1.f);

	glRotatef(90.f, 0, 1, 0);

	auto lazyEdgeRemovalOffset = 50.f;
	auto third = 1.f / 3.f;

	// Render sides
	auto textureOriginX = 0.f;
	for (int i = 0; i < 4; i++) {

		if(i != 1)
		{
			glTranslatef(0.f, 0.f, lazyEdgeRemovalOffset);
		}

		RenderSide(textureOriginX, third);

		if (i != 1)
		{
			glTranslatef(0.f, 0.f, -lazyEdgeRemovalOffset);
		}

		glRotatef(-90.f, 0.f, 1.f, 0.f);
		textureOriginX += 0.25;
	}

	glRotatef(-90.f, 0.f, 1.f, 0.f);
	glRotatef(-90.f, 1.f, 0.f, 0.f);
	glTranslatef(0.f, -_halfSideLength + _yOffset, _halfSideLength - _yOffset + lazyEdgeRemovalOffset);

	// Bottom
	RenderSide(0.25, 0.f);

	glRotatef(180.f, 1.f, 0.f, 0.f);
	glTranslatef(0.f, -_halfSideLength * 2 + _yOffset * 2, 2 * lazyEdgeRemovalOffset);

	// Top
	RenderSide(0.25, third * 2);

	glPopAttrib();
	glPopMatrix();
}

void Skybox::RenderSide(float textureOriginX, float textureOriginY) const
{
	float textureEnd[] = { textureOriginX + 0.25f, textureOriginY + 1.f / 3.f };
	float sideLength = _halfSideLength * 2.f;

	glBegin(GL_TRIANGLES);
	{
		glTexCoord2f(textureOriginX, textureEnd[1]);
		glVertex3f(-_halfSideLength, sideLength - _yOffset, -_halfSideLength);
		glTexCoord2f(textureOriginX, textureOriginY);
		glVertex3f(-_halfSideLength, 0 - _yOffset, -_halfSideLength);
		glTexCoord2f(textureEnd[0], textureOriginY);
		glVertex3f(_halfSideLength, 0 - _yOffset, -_halfSideLength);

		glTexCoord2f(textureEnd[0], textureOriginY);
		glVertex3f(_halfSideLength, 0 - _yOffset, -_halfSideLength);
		glTexCoord2f(textureEnd[0], textureEnd[1]);
		glVertex3f(_halfSideLength, sideLength - _yOffset, -_halfSideLength);
		glTexCoord2f(textureOriginX, textureEnd[1]);
		glVertex3f(-_halfSideLength, sideLength - _yOffset, -_halfSideLength);
	}
	glEnd();
}
