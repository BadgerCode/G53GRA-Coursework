#pragma once
#include "DisplayableObject.h"

class Light : public DisplayableObject
{
public:
	Light(GLenum lightNumber, float x, float y, float z);
	void Display() override;

	// Lighting components
	void SetAmbience(float r, float g, float b, float a);
	void SetDiffuse(float r, float g, float b, float a);
	void SetSpecular(float r, float g, float b, float a);
	void SetPosition(float x, float y, float z);
	void SetAsGlobalLight(bool isGlobalLight);
	void SetOrbDrawing(bool shouldDrawOrb);
private:
	GLenum _lightNumber;

	// Lighting components
	GLfloat _ambience[4];
	GLfloat _diffuse[4];
	GLfloat _specular[4];
	GLfloat _position[4];

	bool _drawOrb;
	bool IsGlobalLight() const;
};
