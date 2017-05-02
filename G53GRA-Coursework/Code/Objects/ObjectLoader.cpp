#include "ObjectLoader.h"
#include "json.hpp"
#include <fstream>
#include "Scene.h"
#include "Utility/Materials.h"

const std::string ObjectLoader::ObjectsPath = "./Code/Data/Objects/";

std::vector<ObjectFace*> ObjectLoader::LoadObject(const std::string& name, const std::string& materialName)
{
	std::vector<ObjectFace*> objectFaces;

	auto path = ObjectsPath + name + ".json";
	
	nlohmann::json parsedJson;
	std::ifstream i(path);
	i >> parsedJson;

	auto customMaterialId = materialName == "" ? -1 : Scene::GetTexture(Materials::GetPath(materialName));

	for (auto face : parsedJson.at("faces"))
	{
		auto objectFace = new ObjectFace();

		objectFace->TextureId = customMaterialId > 0 ? 
			customMaterialId 
			: Scene::GetTexture(Materials::GetPath(face.at("materialName").get<std::string>()));

		objectFace->Vertices = face.at("vertices").get<std::vector<std::vector<float>>>();
		objectFace->Normals = face.at("normals").get<std::vector<std::vector<float>>>();
		objectFace->MaterialCoordinates = face.at("materialCoordinates").get<std::vector<std::vector<float>>>();

		objectFaces.push_back(objectFace);
	}

	return objectFaces;
}
