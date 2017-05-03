#pragma once
#include <vector>
#include "Utility/Materials.h"

class ObjectModel
{
public:
	std::vector<float*> _vertices;
	std::vector<float*> _materialCoordinates;
	std::vector<float*> _normals;
	std::vector<std::vector<int*>> _faces;
	std::vector<int> _faceMaterials;

	static const int FACES_VERTEX_INDEX = 0;
	static const int FACES_MATCOORD_INDEX = 1;
	static const int FACES_NORMAL_INDEX = 2;
};

class ObjectLoader
{
public:
	static ObjectModel LoadObject2(const std::string& name, const std::string& customMaterialName = "");
private:
	static const std::string ObjectsPath;

	static float* parseVector(std::stringstream& lineStream);
	static float* parseTextureCoordinate(std::stringstream& lineStream);
	static std::vector<int*> parseObjectFace(std::stringstream& lineStream);
};