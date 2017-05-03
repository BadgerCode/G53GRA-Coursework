#include "Materials.h"
#include <fstream>
#include "Scene.h"
#include "SOIL.h"


nlohmann::json Materials::_mappedNames;
std::string Materials::_defaultMaterialPath;
std::map<std::string, GLuint> Materials::_materialCache;

void Materials::ReloadMaterials()
{
	printf("Initialising materials list.\n");

	std::ifstream i("./Code/Data/Materials.json");
	i >> _mappedNames;

	_defaultMaterialPath = "";
	_defaultMaterialPath = GetPath("material_missing");

	if(_defaultMaterialPath == "")
	{
		printf("MATERIAL ERROR: Failed to load 'missing texture' material\n");
	}
}

std::string Materials::GetPath(const std::string& name)
{
	try {
		return _mappedNames.at(name);
	}
	catch (std::out_of_range&)
	{
		printf("MATERIAL ERROR: Unknown material: '%s'\n", name.c_str());
		return _defaultMaterialPath;
	}
}

int Materials::Get(const std::string& name)
{
	if(name == "material_none")
	{
		return NONE;
	}

	try
	{
		return _materialCache.at(name);
	}
	catch (std::out_of_range&) {}

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);

	GLuint tex_2d = SOIL_load_OGL_texture
	(
		GetPath(name).c_str(),
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_TEXTURE_REPEATS
	);

	/* check for an error during the load process */
	if (tex_2d == 0)
	{
		printf("MATERIAL ERROR: Error loading material '%s': '%s'\n", name.c_str(), SOIL_last_result());
		return NONE;
	}

	_materialCache.insert(make_pair(name, tex_2d));

	glDisable(GL_TEXTURE_2D);

	return static_cast<int>(tex_2d);
}
