#include "Cube.h"
#include "Scene.h"
#include "StaticObjectCollisionManager.h"

Cube::Cube(float centerPos[], float cubeSize[])
{
	size(cubeSize[0], cubeSize[1], cubeSize[2]);
	position(centerPos[0], centerPos[1], centerPos[2]);
	SetColour(1.f, 0.f, 0.f, 1.f);
	_usingTexture = false;
	_textureScale[0] = 1;
	_textureScale[1] = 1;

	StaticObjectCollisionManager::AddCollisionCube(pos, scale);
}


void Cube::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glTranslatef(pos[0], pos[1], pos[2]);
	glRotatef(rotation[0], 1, 0, 0);
	glRotatef(rotation[1], 0, 1, 0);
	glRotatef(rotation[2], 0, 0, 1);

	auto halfWidth = scale[0] / 2;
	auto halfHeight = scale[1] / 2;
	auto halfDepth = scale[2] / 2;

	if (_usingTexture) {
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_COLOR_MATERIAL);
		glBindTexture(GL_TEXTURE_2D, _textureId);
		glColor4f(1.f, 1.f, 1.f, 1.f);
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
		glColor4fv(_colour);
	}

	glBegin(GL_TRIANGLES);
	{
		// Front
		glNormal3f(0.f, 0.f, 1.f);
		glTexCoord2f(0.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(1.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(0.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(-halfWidth, halfHeight, halfDepth);

		glTexCoord2f(1.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(1.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(halfWidth, halfHeight, halfDepth);
		glTexCoord2f(0.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(-halfWidth, halfHeight, halfDepth);

		// Right
		glNormal3f(1.f, 0.f, 0.f);
		glTexCoord2f(0.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(1.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glTexCoord2f(0.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(halfWidth, halfHeight, halfDepth);

		glTexCoord2f(1.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glTexCoord2f(1.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(halfWidth, halfHeight, -halfDepth);
		glTexCoord2f(0.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(halfWidth, halfHeight, halfDepth);

		// Back
		glNormal3f(0.f, 0.f, -1.f);
		glTexCoord2f(0.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glTexCoord2f(1.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);
		glTexCoord2f(0.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(halfWidth, halfHeight, -halfDepth);

		glTexCoord2f(1.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);
		glTexCoord2f(1.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);
		glTexCoord2f(0.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(halfWidth, halfHeight, -halfDepth);

		// Left
		glNormal3f(-1.f, 0.f, 0.f);
		glTexCoord2f(0.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);
		glTexCoord2f(1.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(0.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);

		glTexCoord2f(1.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(1.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(-halfWidth, halfHeight, halfDepth);
		glTexCoord2f(0.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);

		// Top
		glNormal3f(0.f, 1.f, 0.f);
		glTexCoord2f(0.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(-halfWidth, halfHeight, halfDepth);
		glTexCoord2f(1.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(halfWidth, halfHeight, halfDepth);
		glTexCoord2f(0.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);

		glTexCoord2f(1.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(halfWidth, halfHeight, halfDepth);
		glTexCoord2f(1.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(halfWidth, halfHeight, -halfDepth);
		glTexCoord2f(0.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(-halfWidth, halfHeight, -halfDepth);

		// Bottom
		glNormal3f(0.f, -1.f, 0.f);
		glTexCoord2f(0.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);
		glTexCoord2f(1.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(halfWidth, -halfHeight, -halfDepth);
		glTexCoord2f(1.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(halfWidth, -halfHeight, halfDepth);

		glTexCoord2f(1.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(0.0f / _textureScale[0], 1.0f / _textureScale[1]);
		glVertex3f(-halfWidth, -halfHeight, halfDepth);
		glTexCoord2f(0.0f / _textureScale[0], 0.0f / _textureScale[1]);
		glVertex3f(-halfWidth, -halfHeight, -halfDepth);

	}
	glEnd();
	glPopAttrib();
	glPopMatrix();
}

void Cube::SetTexture(std::string texturePath)
{
	_textureId = Scene::GetTexture(texturePath);
	auto textureNotLoaded = _textureId < 0;
	
	if (textureNotLoaded)
	{
		_textureId = -1;
		_usingTexture = false;
		return;
	}

	_usingTexture = true;
}

void Cube::SetTextureScale(float x, float y)
{
	_textureScale[0] = x;
	_textureScale[1] = y;
}

void Cube::SetColour(float r, float g, float b, float a)
{
	_colour[0] = r;
	_colour[1] = g;
	_colour[2] = b;
	_colour[3] = a;
}
