#include "Object.h"
#include "Utility/Materials.h"

Object::Object(const std::string& objectName, const std::string& customMaterial)
{
	_faces = ObjectLoader::LoadObject(objectName, customMaterial);
}

void Object::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glTranslatef(pos[0], pos[1], pos[2]);
	glRotatef(rotation[0], 1.0f, 0.f, 0.f);
	glRotatef(rotation[1], 0.0f, 1.f, 0.f);
	glRotatef(rotation[2], 0.0f, 0.f, 1.f);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	for (auto face : _faces) {
		glBindTexture(GL_TEXTURE_2D, face->TextureId);
		glColor4f(1.f, 1.f, 1.f, 1.f);

		glBegin(GL_TRIANGLES);
		for (uint32_t i = 0; i < face->Vertices.size(); i++)
		{
			glNormal3f(face->Normals[i][0], face->Normals[i][1], face->Normals[i][2]);
			glTexCoord2f(face->MaterialCoordinates[i][0], face->MaterialCoordinates[i][1]);
			glVertex3f(face->Vertices[i][0], face->Vertices[i][1], face->Vertices[i][2]);
		}
		glEnd();
	}

	glPopAttrib();
	glPopMatrix();
}
