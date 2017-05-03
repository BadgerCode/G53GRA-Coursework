#pragma once
#include <vector>

class ObjectFace
{
public:
	ObjectFace() : TextureId(-1) { }

	int TextureId;
	std::vector<float*> Vertices;
	std::vector<float*> Normals;
	std::vector<float*> MaterialCoordinates;
};

class ObjectLoader
{
public:
	static std::vector<ObjectFace*> LoadObject(const std::string& name, const std::string& customMaterialName = "");
private:
	static const std::string ObjectsPath;

	static float* parseVector(std::stringstream& lineStream);
	static float* parseTextureCoordinate(std::stringstream& lineStream);
	static std::vector<int*> parseObjectFace(std::stringstream& lineStream);
};