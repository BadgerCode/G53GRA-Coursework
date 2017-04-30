#include "Map.h"

Map::Map()
{
	_mapSize = 5000;
	_skybox = new Skybox(5000, "./Textures/skybox.bmp");

	auto lightLevel = -0.35f; // -0.35

	_sunlight = new Light(GL_LIGHT0, 2500.f, 2500.f, -2500.f);
	_sunlight->SetAsGlobalLight(true);
	_sunlight->SetAmbience(lightLevel, lightLevel, lightLevel, 1.f);
	_sunlight->SetDiffuse(0.f, 0.f, 0.f, 1.f);
	_sunlight->SetSpecular(0.f, 0.f, 0.f, 1.f);

	_floorTextureId = Scene::GetTexture("./Textures/grass.bmp");
}

void Map::Display()
{
	_skybox->Display();
	_sunlight->Display();

	RenderFloor();
}

void Map::RenderFloor()
{
	auto halfMapSize = _mapSize / 2;

	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, _floorTextureId);
	glColor4f(1.f, 1.f, 1.f, 1.f);

	glBegin(GL_TRIANGLES);
	glNormal3f(0.f, 1.f, 0.f);

	auto floorSquareSize = 100;
	auto numRowsOrCols = _mapSize / floorSquareSize;

	int left = -halfMapSize;
	int right = left + floorSquareSize;

	for (int i = 0; i < numRowsOrCols; i++)
	{
		int top = -halfMapSize;
		int bottom = top + floorSquareSize;

		for(int j = 0; j < numRowsOrCols; j++)
		{
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(left, 0, top);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(left, 0, bottom);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(right, 0, bottom);

			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(right, 0, bottom);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(right, 0, top);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(left, 0, top);

			top += floorSquareSize;
			bottom += floorSquareSize;
		}

		left += floorSquareSize;
		right += floorSquareSize;
	}

	glEnd();

	glPopAttrib();
	glPopMatrix();
}
