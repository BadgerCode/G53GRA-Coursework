#pragma once
#include <vector>
#include "Services/Materials.h"
#include "ObjectModel.h"

class ObjectLoader
{
public:
	static ObjectModel* LoadObject(const std::string& name);
	static std::string GetPath(const std::string& name);
private:
	static float* parseVector(std::stringstream& lineStream);
	static float* parseTextureCoordinate(std::stringstream& lineStream);
	static std::vector<int*> parseObjectFace(std::stringstream& lineStream);

	static std::map<std::string, ObjectModel*> _modelsCache;
};
