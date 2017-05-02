#pragma once
#include <vector>

class ObjectFace
{
public:
	ObjectFace() : TextureId(-1) { }

	int TextureId;
	std::vector<std::vector<float>> Vertices;
	std::vector<std::vector<float>> Normals;
	std::vector<std::vector<float>> MaterialCoordinates;
};

class ObjectLoader
{
public:
	static std::vector<ObjectFace*> LoadObject(const std::string& name, const std::string& customMaterialName = "");
private:
	static const std::string ObjectsPath;

	static std::vector<int> loadMaterials(std::vector<std::string> materials, std::string customMaterialName);
};