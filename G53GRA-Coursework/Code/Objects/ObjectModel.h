#pragma once
#include <vector>

class ObjectModel
{
public:
	float** Vertices;
	float** UVCoordinates;
	float** Normals;
	int*** Faces;
	int* FaceMaterials;

	int NumVertices;
	int NumUVCoordinates;
	int NumNormals;
	int NumFaces;

	static const int FACES_VERTEX_INDEX = 0;
	static const int FACES_MATCOORD_INDEX = 1;
	static const int FACES_NORMAL_INDEX = 2;

	void SetVertices(std::vector<float*> vertices)
	{
		NumVertices = vertices.size();
		Vertices = new float*[NumVertices];
		for (auto i = 0; i < NumVertices; i++)
		{
			Vertices[i] = vertices[i];
		}
	}

	void SetUVCoordinates(std::vector<float*> uvCoordinates)
	{
		NumUVCoordinates = uvCoordinates.size();
		UVCoordinates = new float*[NumUVCoordinates];
		for (auto i = 0; i < NumUVCoordinates; i++)
		{
			UVCoordinates[i] = uvCoordinates[i];
		}
	}


	void SetNormals(std::vector<float*> normals)
	{
		NumNormals = normals.size();
		Normals = new float*[NumNormals];
		for (auto i = 0; i < NumNormals; i++)
		{
			Normals[i] = normals[i];
		}
	}

	void SetFaces(std::vector<int**> faces, std::vector<int> faceMaterials)
	{
		NumFaces = faces.size();
		Faces = new int**[NumFaces];
		FaceMaterials = new int[NumFaces];

		for (auto i = 0; i < NumFaces; i++)
		{
			Faces[i] = faces[i];
			FaceMaterials[i] = faceMaterials[i];
		}
	}
};
