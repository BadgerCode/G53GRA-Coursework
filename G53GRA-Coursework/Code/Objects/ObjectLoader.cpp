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

#include "ObjectLoader.h"
#include "json.hpp"
#include <fstream>
#include "Utility/Materials.h"

const std::string ObjectLoader::ObjectsPath = "./Code/Data/Models/";

std::vector<ObjectFace*> ObjectLoader::LoadObject(const std::string& name, const std::string& customMaterialName)
{
	std::vector<ObjectFace*> objectFaces;

	auto path = ObjectsPath;
	path.append(name).append(".obj");

	std::ifstream fileStream(path, std::ios_base::in);

	if(!fileStream)
	{
		printf("MODEL ERROR: Error opening '%s' model file.\n", name.c_str());
		return{};
	}

	std::vector<float*> vertices;
	std::vector<float*> textureCoordinates;
	std::vector<float*> normals;

	auto currentMaterial = Materials::NONE;

	auto overrideMaterial = customMaterialName != "";
	if(overrideMaterial)
	{
		currentMaterial = Materials::Get(customMaterialName);
	}

	std::string line;
	while (getline(fileStream, line)) {
		if (line.length() == 0 || line[0] == '#')
		{
			continue;
		}

		std::stringstream lineStream(line);
		std::string firstWord;
		lineStream >> firstWord;

		if(firstWord.length() == 0)
		{
			continue;
		}

		if(firstWord == "v")
		{
			vertices.push_back(parseVector(lineStream));
		}
		else if(firstWord == "vt")
		{
			textureCoordinates.push_back(parseTextureCoordinate(lineStream));
		}
		else if(firstWord == "vn")
		{
			normals.push_back(parseVector(lineStream));
		}
		else if(firstWord == "f")
		{
			auto objectFace = new ObjectFace();
			auto faceIndeces = parseObjectFace(lineStream);

			for (auto i = 0; i < 3; i++)
			{
				auto faceVertex = faceIndeces[i];

				objectFace->MaterialId = currentMaterial;
				objectFace->Vertices.push_back(vertices[faceVertex[0]]);
				objectFace->MaterialCoordinates.push_back(textureCoordinates[faceVertex[1]]);
				objectFace->Normals.push_back(normals[faceVertex[2]]);
			}

			objectFaces.push_back(objectFace);
		}
		else if(firstWord == "usemtl" && !overrideMaterial)
		{
			std::string materialName;
			lineStream >> materialName;

			currentMaterial = Materials::Get(materialName);
		}
	}

	fileStream.close();

//	printf("\nLoaded object %s\n", name.c_str());
//
//	int faceNum = 0;
//	for (auto face : objectFaces)
//	{
//		printf("Face %d\n", faceNum++);
//		printf("Vertices:\n");
//		for (auto vertex : face->Vertices)
//		{
//			printf("%f, %f, %f\n", vertex[0], vertex[1], vertex[2]);
//		}
//		printf("Mat Coords:\n");
//		for (auto vertex : face->MaterialCoordinates)
//		{
//			printf("%f, %f\n", vertex[0], vertex[1]);
//		}
//		printf("Normals:\n");
//		for (auto vertex : face->Normals)
//		{
//			printf("%f, %f, %f\n", vertex[0], vertex[1], vertex[2]);
//		}
//	}

	return objectFaces;
}

float* ObjectLoader::parseVector(std::stringstream& lineStream)
{
	float x, y, z;
	lineStream >> x >> y >> z;

	return new float[3] { x, y, z };
}

float* ObjectLoader::parseTextureCoordinate(std::stringstream& lineStream)
{
	float x, y;
	lineStream >> x >> y;

	return new float[2] { x, y };
}

std::vector<int*> ObjectLoader::parseObjectFace(std::stringstream& lineStream)
{
	std::vector<int*> result;

	for(int i = 0; i < 3; i++)
	{
		auto vertexIndeces = new int[3];
		std::string faceVertex;
		lineStream >> faceVertex;

		auto firstSlashPos = faceVertex.find('/');
		auto secondSlashPos = faceVertex.find('/', firstSlashPos + 1);

		vertexIndeces[0] = std::stoi(faceVertex.substr(0, firstSlashPos).c_str()) - 1;
		vertexIndeces[1] = std::stoi(faceVertex.substr(firstSlashPos + 1, secondSlashPos - firstSlashPos).c_str()) - 1;
		vertexIndeces[2] = std::stoi(faceVertex.substr(secondSlashPos + 1, faceVertex.length() - secondSlashPos).c_str()) - 1;

		result.push_back(vertexIndeces);
	}

	return result;
}
