#pragma once
#include <string>
#include <vector>

class ObjectModelFile
{
public:
	ObjectModelFile(const std::string& filePath);
	void Load();

	std::vector<float*> _vertices;
	std::vector<float*> _textureCoordinates;
	std::vector<float*> _normals;
	std::vector<int**> _faces;
	std::vector<int> _faceMaterials;

private:
	std::string _path;

	float* parseVector(std::stringstream& lineStream);
	float* parseTextureCoordinate(std::stringstream& lineStream);
	int** parseObjectFace(std::stringstream& lineStream);
};
