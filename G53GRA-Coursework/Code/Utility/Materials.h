#pragma once

#include "json.hpp"

class Materials
{
public:
	static void ReloadMaterials();
	static std::string GetPath(std::string name);
	static int Get(std::string name);
private:
	static std::string _defaultTexturePath;
	static nlohmann::json _mappedNames;
};
