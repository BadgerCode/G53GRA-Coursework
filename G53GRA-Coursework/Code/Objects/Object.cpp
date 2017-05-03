#include "Object.h"
#include "Utility/Materials.h"

Object::Object(const std::string& objectName, const std::string& customMaterial)
{
	_model = ObjectLoader::LoadObject2(objectName, customMaterial);
}

void Object::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);
	glRotatef(rotation[0], 1.0f, 0.f, 0.f);
	glRotatef(rotation[1], 0.0f, 1.f, 0.f);
	glRotatef(rotation[2], 0.0f, 0.f, 1.f);

	auto firstItem = true;
	auto currentTextureId = Materials::NONE;

	for (int i = 0; i < _model._faces.size(); i++) {
		auto face = _model._faces[i];
		auto faceMaterial = _model._faceMaterials[i];

		if (firstItem || faceMaterial != currentTextureId) {
			// Texture change

			if(!firstItem)
			{
				// Indicates texture change between faces. End the previous set of faces.
				glEnd();
			}

			firstItem = false;

			glEnable(GL_TEXTURE_2D);
			glEnable(GL_COLOR_MATERIAL);

			currentTextureId = faceMaterial;
			glBindTexture(GL_TEXTURE_2D, currentTextureId);
			glColor4f(1.f, 1.f, 1.f, 1.f);

			glBegin(GL_TRIANGLES);
		}

		for (uint32_t i = 0; i < face.size(); i++)
		{
			auto vertex = face[i];
			auto normal = _model._normals[vertex[_model.FACES_NORMAL_INDEX]];
			auto matCoord = _model._materialCoordinates[vertex[_model.FACES_MATCOORD_INDEX]];
			auto vertexCoords = _model._vertices[vertex[_model.FACES_VERTEX_INDEX]];

			glNormal3f(normal[0], normal[1], normal[2]);
			glTexCoord2f(matCoord[0], matCoord[1]);
			glVertex3f(vertexCoords[0], vertexCoords[1], vertexCoords[2]);
		}
	}
	glEnd();

	glPopAttrib();
	glPopMatrix();
}
