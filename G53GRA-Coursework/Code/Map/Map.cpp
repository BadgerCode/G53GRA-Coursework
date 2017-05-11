#include "Map.h"
#include "Services/Materials.h"
#include "Objects/Object.h"
#include "Lighting/Lantern.h"
#include <fstream>
#include "Configuration.h"
#include "Objects/ObjectLoader.h"
#include "StaticObjectCollisionManager.h"

Map::Map()
{
	_mapSize = 10000.f;
	_skybox = new Skybox(_mapSize * 2.f);

	_lightLevel = -0.35f;

	loadCollisionCubes();
	loadObjects();
	loadLights();
}

void Map::Display()
{
	_skybox->Display();

	for(auto i = 0; i < _numObjects; i++)
	{
		_mapObjects[i]->Display();
	}

	for (auto i = 0; i < _numLights; i++)
	{
		_mapLights[i]->Display();
	}
}

void Map::HandleKey(unsigned char key, int state, int x, int y)
{
	if(key == 'g' && state == 0)
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

void Map::Update(const double& deltaTime)
{
	for (auto animatedObject : _animatedObjects)
	{
		animatedObject->Update(deltaTime);
	}
}

void Map::loadCollisionCubes()
{
	nlohmann::json parsedJson;
	std::ifstream fileStream(Configuration::DataPath + "CollisionBoxes.json");
	fileStream >> parsedJson;

	for (auto collisionCube : parsedJson.at("staticObjects"))
	{
		auto min = collisionCube.at("min").get<std::vector<float>>();
		auto max = collisionCube.at("max").get<std::vector<float>>();
		StaticObjectCollisionManager::AddCollisionCube(min, max);
	}
}

void Map::loadObjects()
{
	nlohmann::json parsedJson;
	std::ifstream fileStream(Configuration::DataPath + "Map.json");
	fileStream >> parsedJson;

	auto jsonMapObjects = parsedJson.at("objects").get<std::vector<nlohmann::json>>();

	_numObjects = jsonMapObjects.size();
	_mapObjects = new DisplayableObject*[_numObjects];

	for (int i = 0; i < _numObjects; i++)
	{
		auto mapObject = jsonMapObjects[i];

		auto objectName = mapObject["name"].get<std::string>();
		auto pos = mapObject["pos"].get<std::vector<float>>();
		auto rotation = mapObject["rotation"].get<std::vector<float>>();
		auto scale = mapObject["scale"].get<std::vector<float>>();

		_mapObjects[i] = ObjectLoader::LoadObject(objectName);
		_mapObjects[i]->position(pos[0], pos[1], pos[2]);
		_mapObjects[i]->orientation(rotation[0], rotation[1], rotation[2]);
		_mapObjects[i]->size(scale[0], scale[1], scale[2]);
	}
}

void Map::loadLights()
{
	std::vector<Light*> lights;

	{
		_sunlight = new Light(_mapSize - 6600, _mapSize - 2200, -_mapSize + 100);
		_sunlight->SetOrbDrawing(false);
		_sunlight->SetAsGlobalLight(true);
		_sunlight->SetAmbience(_lightLevel, _lightLevel, _lightLevel, 1.f);
		_sunlight->SetDiffuse(0.f, 0.f, 0.f, 1.f);
		_sunlight->SetSpecular(0.f, 0.f, 0.f, 1.f);
		lights.push_back(_sunlight);
	}

	{
		auto lantern = new Lantern(-180.f, 90.f, 210.f);
		lights.push_back(lantern);
	}

	{
		auto lantern = new Lantern(175.f, 80.f, 215.f);
		lights.push_back(lantern);
	}

	{
		auto fireplace = new Fire(0.f, 26.875f, -234.061f);
		fireplace->SetOrbDrawing(false);
		fireplace->SetAmbience(0.8f, 0.8f, 0.7f, 1.f);
		fireplace->SetDiffuse(0.8f, 0.8f, 0.6f, 1.f);
		fireplace->SetSpecular(0.f, 0.f, 0.f, 1.f);
		fireplace->SetDistance(350.f);

		lights.push_back(fireplace);
		_animatedObjects.push_back(fireplace);
	}

	_numLights = lights.size();
	_mapLights = new Light*[_numLights];

	for(int i = 0; i < _numLights; i++)
	{
		_mapLights[i] = lights[i];
	}
}
