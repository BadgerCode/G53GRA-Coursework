#pragma once
#include <vector>
#include "Services/Materials.h"
#include "ObjectModel.h"
#include "Object.h"

class ObjectLoader
{
public:
	static Object* LoadObject(const std::string& name);

	static std::string GetPath(const std::string& name);
private:
	static ObjectModel* loadModel(const std::string& name);
	std::vector<float*> _vertices;
	std::vector<float*> _textureCoordinates;
	std::vector<float*> _normals;
	std::vector<int**> _faces;
	std::vector<int> _faceMaterials;

	static std::map<std::string, ObjectModel*> _modelsCache;
};
