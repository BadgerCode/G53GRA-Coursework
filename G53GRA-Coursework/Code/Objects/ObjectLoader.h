#pragma once
#include <vector>

class ObjectFace
{
public:
	ObjectFace() { }

	int TextureId;
	std::vector<std::vector<float>> Vertices;
	std::vector<std::vector<float>> Normals;
	std::vector<std::vector<float>> MaterialCoordinates;
};

class ObjectLoader
{
public:
	static std::vector<ObjectFace*> LoadObject(const std::string& name, const std::string& materialName = "");
private:
	static const std::string ObjectsPath;
};