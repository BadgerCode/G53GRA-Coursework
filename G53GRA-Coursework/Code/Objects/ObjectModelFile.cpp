/*
* LIMITATIONS
* Assumes:
	* The material name in "usemtl" is a valid material name in materials.json
* Ignores:
	* mtllib
	* Anything other than v, vt, vn, f, usemtl
	* More than 3 vertices per face
* Throws an error:
	* If not every face vertex has a vertex index
	* If a face has an invalid index for the vertex, texture index or normal
*/

#include "ObjectModelFile.h"
#include "Services/Materials.h"
#include <fstream>

ObjectModelFile::ObjectModelFile(const std::string& filePath)
{
	_path = filePath;
}

void ObjectModelFile::Load()
{
	std::ifstream fileStream(_path, std::ios_base::in);

	if (!fileStream)
	{
		printf("MODEL ERROR: Error opening '%s' model file.\n", _path.c_str());
		return;
	}

	auto noRender = false;
	auto currentMaterial = Materials::NONE;

	std::string line;
	while (getline(fileStream, line)) {
		if (line.length() == 0 || line[0] == '#')
		{
			continue;
		}

		std::stringstream lineStream(line);
		std::string firstWord;
		lineStream >> firstWord;

		if (firstWord.length() == 0)
		{
			continue;
		}

		if (firstWord == "v")
		{
			_vertices.push_back(parseVector(lineStream));
		}
		else if (firstWord == "vt")
		{
			_textureCoordinates.push_back(parseTextureCoordinate(lineStream));
		}
		else if (firstWord == "vn")
		{
			_normals.push_back(parseVector(lineStream));
		}
		else if (firstWord == "f")
		{
			if (noRender) continue;

			_faces.push_back(parseObjectFace(lineStream));
			_faceMaterials.push_back(currentMaterial);
		}
		else if (firstWord == "usemtl")
		{
			std::string materialName;
			lineStream >> materialName;

			if (materialName == "material_norender")
			{
				noRender = true;
				currentMaterial = Materials::NONE;
			}
			else {
				noRender = false;
				currentMaterial = Materials::Get(materialName);
			}
		}
	}

	fileStream.close();
}

float* ObjectModelFile::parseVector(std::stringstream& lineStream)
{
	float x, y, z;
	lineStream >> x >> y >> z;

	return new float[3]{ x, y, z };
}

float* ObjectModelFile::parseTextureCoordinate(std::stringstream& lineStream)
{
	float x, y;
	lineStream >> x >> y;

	return new float[2]{ x, y };
}

int** ObjectModelFile::parseObjectFace(std::stringstream& lineStream)
{
	auto result = new int*[3];

	for (int i = 0; i < 3; i++)
	{
		auto vertexIndeces = new int[3]{ -1, -1, -1 };

		std::string encodedFaceVertex;
		lineStream >> encodedFaceVertex;

		auto firstSlashPos = encodedFaceVertex.find('/');
		auto secondSlashPos = encodedFaceVertex.find('/', firstSlashPos + 1);

		auto textureCoordinateExists = secondSlashPos - firstSlashPos > 1;
		auto normalCoordinateExists = encodedFaceVertex.length() - secondSlashPos > 1;

		vertexIndeces[0] = std::stoi(encodedFaceVertex.substr(0, firstSlashPos).c_str()) - 1;

		if (textureCoordinateExists) {
			vertexIndeces[1] = std::stoi(encodedFaceVertex.substr(firstSlashPos + 1, secondSlashPos - firstSlashPos).c_str()) - 1;
		}

		if (normalCoordinateExists) {
			vertexIndeces[2] = std::stoi(encodedFaceVertex.substr(secondSlashPos + 1, encodedFaceVertex.length() - secondSlashPos).c_str()) - 1;
		}

		result[i] = vertexIndeces;
	}

	return result;
}