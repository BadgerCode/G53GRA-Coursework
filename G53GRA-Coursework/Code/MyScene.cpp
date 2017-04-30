#include "MyScene.h"
#include "Cube.h"
#include "Skybox.h"
#include "Light.h"
#include "Map.h"
#include "Flashlight.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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

	AddObjectToScene(flashLight);

	auto light1 = new Light(GL_LIGHT2, -575.f, 50.f, 70.f);
	light1->SetAmbience(1.f, 1.f, 1.f, 1.f);
	light1->SetDiffuse(0.8f, 0.8f, 0.8f, 1.f);
	light1->SetSpecular(1.f, 1.f, 1.f, 1.f);

	AddObjectToScene(light1);
}

void MyScene::SetupObjects()
{
	auto object1 = new Cube(100, 50, 0);
	object1->SetTexture("./Textures/baked_beans_teaser.bmp");
	AddObjectToScene(object1);

	auto object2 = new Cube(-450, 50, 0);
	object2->SetColour(1, 0, 0, 1);
	AddObjectToScene(object2);
}
