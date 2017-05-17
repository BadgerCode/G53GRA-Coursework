#include "Map.h"
#include "Services/Materials.h"
#include "Lighting/Lantern.h"
#include <fstream>
#include "Configuration.h"
#include "Objects/ObjectLoader.h"
#include "StaticObjectCollisionManager.h"
#include "JSON/json.h"
#include <sstream>

Map::Map()
{
	_mapSize = 10000.f;
	_skybox = new Skybox();

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

void Map::Update(const double& deltaTime)
{
	for (auto animatedObject : _animatedObjects)
	{
		animatedObject->Update(deltaTime);
	}
}

void Map::loadCollisionCubes()
{
	auto path = Configuration::DataPath + "CollisionBoxes.json";
	std::ifstream fileStream(path, std::ios_base::in);

	if (!fileStream)
	{
		printf("MAP ERROR: Error opening '%s' collision cubes file.\n", path.c_str());
		return;
	}

	Json::Value json;
	fileStream >> json;

	auto staticObjects = json["staticObjects"];
	for (auto collisionCube = staticObjects.begin(); collisionCube != staticObjects.end(); ++collisionCube)
	{
		auto min = std::vector<float>();
		auto max = std::vector<float>();

		auto minJson = (*collisionCube)["min"];
		auto maxJson = (*collisionCube)["max"];

		min.push_back(minJson[0].asFloat());
		min.push_back(minJson[1].asFloat());
		min.push_back(minJson[2].asFloat());

		max.push_back(maxJson[0].asFloat());
		max.push_back(maxJson[1].asFloat());
		max.push_back(maxJson[2].asFloat());

		StaticObjectCollisionManager::AddCollisionCube(min, max);
	}
}

void Map::loadObjects()
{
	auto path = Configuration::DataPath + "Map.json";
	std::ifstream fileStream(path, std::ios_base::in);

	if (!fileStream)
	{
		printf("MAP ERROR: Error opening '%s' map file.\n", path.c_str());
		return;
	}

	Json::Value json;
	fileStream >> json;

	auto mapObjects = json["objects"];
	_numObjects = mapObjects.size();
	_mapObjects = new DisplayableObject*[_numObjects];

	auto i = 0;

	for (auto mapObject = mapObjects.begin(); mapObject != mapObjects.end(); ++mapObject)
	{
		auto pos = std::vector<float>();
		auto rotation = std::vector<float>();
		auto scale = std::vector<float>();

		auto objectName = (*mapObject)["name"].asString();
		auto posJson = (*mapObject)["pos"];
		auto rotJson = (*mapObject)["rotation"];
		auto scaleJson = (*mapObject)["scale"];

		pos.push_back(posJson[0].asFloat());
		pos.push_back(posJson[1].asFloat());
		pos.push_back(posJson[2].asFloat());

		rotation.push_back(rotJson[0].asFloat());
		rotation.push_back(rotJson[1].asFloat());
		rotation.push_back(rotJson[2].asFloat());

		scale.push_back(scaleJson[0].asFloat());
		scale.push_back(scaleJson[1].asFloat());
		scale.push_back(scaleJson[2].asFloat());

		_mapObjects[i] = ObjectLoader::LoadObject(objectName);
		_mapObjects[i]->position(pos[0], pos[1], pos[2]);
		_mapObjects[i]->orientation(rotation[0], rotation[1], rotation[2]);
		_mapObjects[i]->size(scale[0], scale[1], scale[2]);

		i++;
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
		_animatedObjects.push_back(lantern);
	}

	{
		auto lantern = new Lantern(175.f, 80.f, 215.f);
		lights.push_back(lantern);
		_animatedObjects.push_back(lantern);
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

	for(auto i = 0; i < _numLights; i++)
	{
		_mapLights[i] = lights[i];
	}
}
