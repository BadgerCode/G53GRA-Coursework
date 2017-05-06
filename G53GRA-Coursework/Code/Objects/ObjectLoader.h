#pragma once
#include <vector>
#include "Utility/Materials.h"
#include "ObjectModel.h"

class ObjectLoader
{
public:
	static ObjectModel LoadObject(const std::string& name, const std::string& customMaterialName = "");
	static std::string GetPath(const std::string& name);
private:
	static float* parseVector(std::stringstream& lineStream);
	static float* parseTextureCoordinate(std::stringstream& lineStream);
	static std::vector<int*> parseObjectFace(std::stringstream& lineStream);
};
