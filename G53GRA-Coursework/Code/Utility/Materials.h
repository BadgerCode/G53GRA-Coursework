#pragma once

#include "json.hpp"
#include "GlutDependency.h"

class Materials
{
public:
	static void ReloadMaterials();
	static std::string GetPath(std::string name);
	static int Get(std::string name);
private:
	static std::string _defaultMaterialPath;
	static nlohmann::json _mappedNames;
	static std::map<std::string, GLuint> _materialCache;
};
