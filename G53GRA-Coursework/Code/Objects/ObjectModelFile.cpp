/*
* LIMITATIONS
* Ignores:
* mtllib
* Anything other than v, vt, vn, f, usemtl
* Material file names in usemtl. Assumes it is a valid material name from materials.json
* Throws error:
* If a face has more than 3 vertices
* If not every face vertex has a vertex index, texture index and normal index
* If a face has an invalid index for the vertex, texture index or normal
* If a face tries to use a vertex, texture index or normal before it is defined
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

			auto face = new int*[3];
			auto faceVertices = parseObjectFace(lineStream);

			for (int i = 0; i < 3; i++)
			{
				auto faceVertex = faceVertices[i];

				auto faceIndeces = new int[3];
				faceIndeces[0] = faceVertex[0];
				faceIndeces[1] = faceVertex[1];
				faceIndeces[2] = faceVertex[2];

				face[i] = faceIndeces;
			}

			_faces.push_back(face);
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

std::vector<int*> ObjectModelFile::parseObjectFace(std::stringstream& lineStream)
{
	std::vector<int*> result;

	for (int i = 0; i < 3; i++)
	{
		auto vertexIndeces = new int[3]{ -1, -1, -1 };
		std::string faceVertex;
		lineStream >> faceVertex;

		auto firstSlashPos = faceVertex.find('/');
		auto secondSlashPos = faceVertex.find('/', firstSlashPos + 1);

		vertexIndeces[0] = std::stoi(faceVertex.substr(0, firstSlashPos).c_str()) - 1;
		if (secondSlashPos - firstSlashPos > 1) {
			vertexIndeces[1] = std::stoi(faceVertex.substr(firstSlashPos + 1, secondSlashPos - firstSlashPos).c_str()) - 1;
		}
		if (faceVertex.length() - secondSlashPos > 1) {
			vertexIndeces[2] = std::stoi(faceVertex.substr(secondSlashPos + 1, faceVertex.length() - secondSlashPos).c_str()) - 1;
		}

		result.push_back(vertexIndeces);
	}

	return result;
}