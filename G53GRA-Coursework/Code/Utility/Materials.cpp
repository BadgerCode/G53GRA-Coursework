#include "Materials.h"
#include "json.hpp"
#include <fstream>
#include "Scene.h"


nlohmann::json Materials::_mappedNames;
std::string Materials::_defaultTexturePath;

void Materials::ReloadMaterials()
{
	printf("Initialising materials list.\n");

	std::ifstream i("./Code/Data/Materials.json");
	i >> _mappedNames;

	_defaultTexturePath = "";
	_defaultTexturePath = GetPath("material_missing");

	if(_defaultTexturePath == "")
	{
		printf("MATERIAL ERROR: Failed to load missing texture\n");
	}
}

std::string Materials::GetPath(std::string name)
{
	try {
		return _mappedNames.at(name);
	}
	catch (std::out_of_range&)
	{
		printf("MATERIAL ERROR: Unknown material: '%s'\n", name.c_str());
		return _defaultTexturePath;
	}
}

int Materials::Get(std::string name)
{
	return Scene::GetTexture(GetPath(name));
}
