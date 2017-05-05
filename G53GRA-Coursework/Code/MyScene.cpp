#include "MyScene.h"
#include "Utility/Materials.h"
#include "Map/Map.h"
#include "Lighting/Flashlight.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	Materials::ReloadMaterials();

	AddFlashlight();
	AddObjectToScene(new Map());
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 100000.0);
}

void MyScene::AddFlashlight()
{
	auto flashLight = new Flashlight(GL_LIGHT1);
	flashLight->SetAmbience(0.25f, 0.25f, 0.25f, 1.f);
	flashLight->SetDiffuse(0.4f, 0.4f, 0.4f, 1.f);
	flashLight->SetSpecular(1.f, 1.f, 1.f, 1.f);
	flashLight->SetDistance(300.f);

	AddObjectToScene(flashLight);
}
