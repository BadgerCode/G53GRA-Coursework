#include "ObjectLoader.h"
#include <fstream>
#include "Configuration.h"
#include "ObjectModelFile.h"

std::map<std::string, ObjectModel*> ObjectLoader::_modelsCache;

Object* ObjectLoader::LoadObject(const std::string& name)
{
	try
	{
		return new Object(_modelsCache.at(name));
	}
	catch (std::out_of_range&)
	{
		auto model = loadModel(name);
		_modelsCache.insert(make_pair(name, model));

		return new Object(model);
	}
}

ObjectModel* ObjectLoader::loadModel(const std::string& name)
{
	auto file = new ObjectModelFile(GetPath(name));
	file->Load();

	auto model = new ObjectModel();
	model->SetFaces(file->_faces, file->_faceMaterials);
	model->SetVertices(file->_vertices);
	model->SetUVCoordinates(file->_textureCoordinates);
	model->SetNormals(file->_normals);

	delete file;

	return model;
}

std::string ObjectLoader::GetPath(const std::string& name)
{
	return Configuration::ModelsPath + name + ".obj";
}
