#include "Map.h"
#include "Utility/Materials.h"
#include "Objects/Object.h"
#include "Lighting/Lantern.h"
#include <fstream>
#include "Configuration.h"

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
	int numLights = 3;

	nlohmann::json parsedJson;
	std::ifstream fileStream(Configuration::DataPath + "Map.json");
	fileStream >> parsedJson;

	auto mapObjects = parsedJson.at("objects").get<std::vector<nlohmann::json>>();

	_numObjects = mapObjects.size() + numLights;
	_mapObjects = new DisplayableObject*[_numObjects];

	for (int i = 0; i < _numObjects - numLights; i++)
	{
		auto mapObject = mapObjects[i];
		auto pos = mapObject["pos"].get<std::vector<float>>();
		auto rotation = mapObject["rotation"].get<std::vector<float>>();

		auto object = new Object(mapObject["name"].get<std::string>());
		object->position(pos[0], pos[1], pos[2]);
		object->orientation(rotation[0], rotation[1], rotation[2]);

		_mapObjects[i] = object;
	}

	{
		auto lantern = new Lantern(GL_LIGHT2, -180.f, 90.f, 210.f);
		_mapObjects[_numObjects - 3] = lantern;
	}

	{
		auto lantern = new Lantern(GL_LIGHT3, 175.f, 80.f, 215.f);
		_mapObjects[_numObjects - 2] = lantern;
	}

	{
		auto fireplace = new Fire(GL_LIGHT4, 0.f, 46.875f, -220.f);
		fireplace->SetAmbience(0.8f, 0.8f, 0.7f, 1.f);
		fireplace->SetDiffuse(0.8f, 0.8f, 0.6f, 1.f);
		fireplace->SetSpecular(0.f, 0.f, 0.f, 1.f);
		fireplace->SetDistance(350.f);

		_mapObjects[_numObjects - 1] = fireplace;
	}
}
