#pragma once

#include "GlutDependency.h"
#include <string>
#include <map>

class Materials
{
public:
	static void ReloadMaterials();
	static std::string GetPath(const std::string& name);
	static int Get(const std::string& name);
	static const int NONE = -1;
private:
	static std::string _defaultMaterialPath;
	static std::map<std::string, std::string> _mappedNames;
	static std::map<std::string, GLuint> _materialCache;
};
