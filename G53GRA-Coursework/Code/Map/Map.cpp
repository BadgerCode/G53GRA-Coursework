#include "Map.h"
#include "Utility/Materials.h"
#include "Light.h"

Map::Map()
{
	_mapSize = 10000.f;
	_skybox = new Skybox(_mapSize * 2.f);

	_lightLevel = -0.35f;

	_sunlight = new Light(GL_LIGHT0, _mapSize - 6600, _mapSize - 2200, -_mapSize + 100);
	_sunlight->SetOrbDrawing(false);
	_sunlight->SetAsGlobalLight(true);
	_sunlight->SetAmbience(_lightLevel, _lightLevel, _lightLevel, 1.f);
	_sunlight->SetDiffuse(0.f, 0.f, 0.f, 1.f);
	_sunlight->SetSpecular(0.f, 0.f, 0.f, 1.f);

	_floorMaterial = Materials::Get("material_grass");
}

void Map::Display()
{
	_skybox->Display();
	_sunlight->Display();

//	RenderFloor();
}

void Map::HandleKey(unsigned char key, int state, int x, int y)
{
	if(key == 'f' && state == 0)
	{
		if(_debugEnableLighting)
		{
			_debugEnableLighting = false;
			_sunlight->SetAmbience(1, 1, 1, 1.f);
		}
		else
		{
			_debugEnableLighting = true;
			_sunlight->SetAmbience(_lightLevel, _lightLevel, _lightLevel, 1.f);
		}
	}
}

void Map::RenderFloor()
{
	auto halfMapSize = _mapSize / 2;

	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	glBindTexture(GL_TEXTURE_2D, _floorMaterial);
	glColor4f(1.f, 1.f, 1.f, 1.f);

	glBegin(GL_TRIANGLES);
	glNormal3f(0.f, 1.f, 0.f);

	auto floorSquareSize = 100;
	auto numRowsOrCols = _mapSize / floorSquareSize;

	float floorY = 0;
	float left = -halfMapSize;
	float right = left + floorSquareSize;

	for (int i = 0; i < numRowsOrCols; i++)
	{
		float top = -halfMapSize;
		float bottom = top + floorSquareSize;

		for(int j = 0; j < numRowsOrCols; j++)
		{
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(left, floorY, top);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(left, floorY, bottom);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(right, floorY, bottom);

			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(right, floorY, bottom);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(right, floorY, top);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(left, floorY, top);

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
