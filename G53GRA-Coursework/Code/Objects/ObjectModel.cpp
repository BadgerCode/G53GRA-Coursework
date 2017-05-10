#include "ObjectModel.h"
#include "Services/GlutDependency.h"
#include "Services/Materials.h"

void ObjectModel::Render() const
{
	auto alreadyRenderedFaces = false;
	auto currentTextureId = Materials::NONE;

	for (auto faceIdx = 0; faceIdx < NumFaces; faceIdx++)
	{
		auto faceMaterial = FaceMaterials[faceIdx];
		auto textureHasChanged = faceMaterial != currentTextureId;

		if (textureHasChanged || !alreadyRenderedFaces)
		{
			currentTextureId = faceMaterial;

			if (alreadyRenderedFaces)
			{
				glEnd();
			}

			beginRenderingSetOfFaces(currentTextureId);
			alreadyRenderedFaces = true;
		}

		renderFace(Faces[faceIdx]);
	}

	if (alreadyRenderedFaces)
	{
		glEnd();
	}
}

void ObjectModel::beginRenderingSetOfFaces(int textureId)
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	glBindTexture(GL_TEXTURE_2D, textureId);
	glColor4f(1.f, 1.f, 1.f, 1.f);

	glBegin(GL_TRIANGLES);
}

void ObjectModel::renderFace(int** face) const
{
	for (uint32_t vertexIdx = 0; vertexIdx < 3; vertexIdx++)
	{
		auto vertex = face[vertexIdx];

		auto normalIndex = vertex[FACES_NORMAL_INDEX];
		if (normalIndex > -1)
		{
			auto normal = Normals[normalIndex];
			glNormal3f(normal[0], normal[1], normal[2]);
		}

		auto matCoordIndex = vertex[FACES_MATCOORD_INDEX];
		if (matCoordIndex > -1) {
			auto matCoord = UVCoordinates[matCoordIndex];
			glTexCoord2f(matCoord[0], matCoord[1]);
		}

		auto vertexCoords = Vertices[vertex[FACES_VERTEX_INDEX]];
		glVertex3f(vertexCoords[0], vertexCoords[1], vertexCoords[2]);
	}
}

void ObjectModel::SetVertices(std::vector<float*> vertices)
{
	NumVertices = vertices.size();
	Vertices = new float*[NumVertices];
	for (auto i = 0; i < NumVertices; i++)
	{
		Vertices[i] = vertices[i];
	}
}

void ObjectModel::SetUVCoordinates(std::vector<float*> uvCoordinates)
{
	NumUVCoordinates = uvCoordinates.size();
	UVCoordinates = new float*[NumUVCoordinates];
	for (auto i = 0; i < NumUVCoordinates; i++)
	{
		UVCoordinates[i] = uvCoordinates[i];
	}
}

void ObjectModel::SetNormals(std::vector<float*> normals)
{
	NumNormals = normals.size();
	Normals = new float*[NumNormals];
	for (auto i = 0; i < NumNormals; i++)
	{
		Normals[i] = normals[i];
	}
}

void ObjectModel::SetFaces(std::vector<int**> faces, std::vector<int> faceMaterials)
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