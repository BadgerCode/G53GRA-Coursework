#include "ObjectLoader.h"
#include "json.hpp"
#include <fstream>
#include "Utility/Materials.h"

const std::string ObjectLoader::ObjectsPath = "./Code/Data/Objects/";

std::vector<ObjectFace*> ObjectLoader::LoadObject(const std::string& name, const std::string& customMaterialName)
{
	std::vector<ObjectFace*> objectFaces;

	auto path = ObjectsPath + name + ".json";
	
	nlohmann::json parsedJson;
	std::ifstream fileStream(path);
	fileStream >> parsedJson;

	auto materials = parsedJson.at("materials").get<std::vector<std::string>>();
	auto loadedMaterials = loadMaterials(materials, customMaterialName);

	for (auto face : parsedJson.at("faces"))
	{
		auto objectFace = new ObjectFace();

		objectFace->TextureId = loadedMaterials[face.at("matIdx").get<int>()];
		objectFace->Vertices = face.at("vertices").get<std::vector<std::vector<float>>>();
		objectFace->Normals = face.at("normals").get<std::vector<std::vector<float>>>();
		objectFace->MaterialCoordinates = face.at("materialCoordinates").get<std::vector<std::vector<float>>>();

		objectFaces.push_back(objectFace);
	}

	return objectFaces;
}

std::vector<int> ObjectLoader::loadMaterials(std::vector<std::string> materials, std::string customMaterialName)
{
	std::vector<int> loadedMaterials = {};

	auto useCustomMaterial = customMaterialName != "";
	if (useCustomMaterial)
	{
		auto customMaterial = Materials::Get(customMaterialName);
		for (uint32_t i = 0; i < materials.size(); i++)
		{
			loadedMaterials.push_back(customMaterial);
		}
	}
	else
	{
		for (auto material : materials)
		{
			loadedMaterials.push_back(Materials::Get(material));
		}
	}

	return loadedMaterials;
}
