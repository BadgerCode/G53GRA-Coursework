#include "Map.h"
#include "Utility/Materials.h"
#include "Objects/Object.h"
#include "Objects/Lantern.h"

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

	loadObjects();
}

void Map::Display()
{
	_skybox->Display();
	_sunlight->Display();
	for(auto i = 0; i < _numObjects; i++)
	{
		_mapObjects[i]->Display();
	}
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
	else if(key == 'r' && state == 0)
	{
		float px, py, pz;
		Scene::GetCamera()->GetEyePosition(px, py, pz);
		printf("%f, %f, %f\n", px, py, pz);
	}
}

void Map::loadObjects()
{
	std::vector<DisplayableObject*> mapObjects;

	{
		auto object = new Object("Map/House");
		mapObjects.push_back(object);
	}

	{
		auto object = new Object("Table");
		object->position(227.f, 27.5f, 210.f);
		mapObjects.push_back(object);
	}

	{
		auto lantern = new Lantern(GL_LIGHT2, -180.f, 90.f, 210.f);
		mapObjects.push_back(lantern);
	}

	{
		auto lantern = new Lantern(GL_LIGHT3, 175.f, 80.f, 215.f);
		mapObjects.push_back(lantern);
	}

	{
		auto fireplace = new Light(GL_LIGHT4, 0.f, 46.875f, -220.f);
		fireplace->SetAmbience(1.f, 1.f, 1.f, 1.f);
		fireplace->SetDiffuse(0.8f, 0.8f, 0.8f, 1.f);
		fireplace->SetSpecular(1.f, 1.f, 1.f, 1.f);
		fireplace->SetDistance(400.f);

		mapObjects.push_back(fireplace);
	}

	setObjects(mapObjects);
}

void Map::setObjects(std::vector<DisplayableObject*> objects)
{
	_numObjects = objects.size();
	_mapObjects = new DisplayableObject*[_numObjects];
	for (int i = 0; i < _numObjects; i++)
	{
		_mapObjects[i] = objects[i];
	}
}
