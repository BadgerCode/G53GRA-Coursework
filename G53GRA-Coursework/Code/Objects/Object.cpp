#include "Object.h"
#include "Utility/Materials.h"
#include "Utility/ExtraMaths.h"

Object::Object(const std::string& objectName, const std::string& customMaterial)
{
	_model = ObjectLoader::LoadObject(objectName, customMaterial);
}

void Object::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);

	auto xRadians = degreesToRadians(rotation[0]);
	auto yRadians = degreesToRadians(rotation[1]);

	auto cosX = static_cast<GLfloat>(cos(xRadians));
	auto cosY = static_cast<GLfloat>(cos(yRadians));
	auto sinX = static_cast<GLfloat>(sin(xRadians));
	auto sinY = static_cast<GLfloat>(sin(yRadians));

	glRotatef(rotation[0], 1.0f, 0.f, 0.f);
	glRotatef(rotation[1], 0.0f, cosX, sinX);
	glRotatef(rotation[2], sinY * cosX, -sinX, cosY * cosX);

	glScalef(scale[0], scale[1], scale[2]);

	auto firstItem = true;
	auto currentTextureId = Materials::NONE;

	for (auto faceIdx = 0; faceIdx < _model.NumFaces; faceIdx++) {
		auto face = _model.Faces[faceIdx];
		auto faceMaterial = _model.FaceMaterials[faceIdx];

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

		for (uint32_t vertexIdx = 0; vertexIdx < 3; vertexIdx++)
		{
			auto vertex = face[vertexIdx];
			
			auto normalIndex = vertex[_model.FACES_NORMAL_INDEX];
			if(normalIndex > -1)
			{
				auto normal = _model.Normals[normalIndex];
				glNormal3f(normal[0], normal[1], normal[2]);
			}

			auto matCoordIndex = vertex[_model.FACES_MATCOORD_INDEX];
			if (matCoordIndex > -1) {
				auto matCoord = _model.UVCoordinates[matCoordIndex];
				glTexCoord2f(matCoord[0], matCoord[1]);
			}

			auto vertexCoords = _model.Vertices[vertex[_model.FACES_VERTEX_INDEX]];
			glVertex3f(vertexCoords[0], vertexCoords[1], vertexCoords[2]);
		}
	}
	glEnd();

	glPopAttrib();
	glPopMatrix();
}
