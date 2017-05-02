#include "MyScene.h"
#include "Light.h"
#include "Flashlight.h"
#include "Utility/Materials.h"
#include "Map/Map.h"
#include "Map/House.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	Materials::ReloadMaterials();

	SetupLighting();
	AddObjectToScene(new Map());
	SetupObjects();
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 100000.0);
}

void MyScene::SetupLighting()
{
	auto flashLight = new Flashlight(GL_LIGHT1);
	flashLight->SetAmbience(0.25f, 0.25f, 0.25f, 1.f);
	flashLight->SetDiffuse(0.4f, 0.4f, 0.4f, 1.f);
	flashLight->SetSpecular(1.f, 1.f, 1.f, 1.f);
	flashLight->SetDistance(300.f);

	AddObjectToScene(flashLight);

	{
		auto houseLight = new Light(GL_LIGHT2, 0.f, 150.f, 0.f);
		houseLight->SetAmbience(1.f, 1.f, 1.f, 1.f);
		houseLight->SetDiffuse(0.8f, 0.8f, 0.8f, 1.f);
		houseLight->SetSpecular(1.f, 1.f, 1.f, 1.f);
		houseLight->SetDistance(750.f);

		AddObjectToScene(houseLight);
	}
}

void MyScene::SetupObjects()
{
	{
		float pos[3] = { 100.f, 50.f, 0.f };
		float size[3] = { 100.f, 100.f, 100.f };

		auto object = new Cube(pos, size);
		object->SetTexture("material_placeholder");
		AddObjectToScene(object);
	}

	{
		float pos[3] = { -400.f, 50.f, 0.f };
		float size[3] = { 100.f, 100.f, 100.f };

		auto object = new Cube(pos, size);
		object->SetColour(1, 0, 0, 1);
		AddObjectToScene(object);
	}

	{
		auto object = new House();
		AddObjectToScene(object);
	}
}
