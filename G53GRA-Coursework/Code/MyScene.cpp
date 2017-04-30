#include "MyScene.h"
#include "TestObject.h"
#include "Skybox.h"
#include "Light.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	SetupLighting();
	AddObjectToScene(new Skybox(5000, "./Textures/skybox.bmp"));
	AddObjectToScene(new TestObject(0, 0, 0));
	AddObjectToScene(new TestObject(-450, 0, 0));
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 9000.0);
}

void MyScene::SetupLighting()
{
	auto sunlight = new Light(GL_LIGHT0, 5000.f, 5000.f, -5000.f);
	sunlight->SetAsGlobalLight(true);
	sunlight->SetAmbience(-0.15, -0.15, -0.15, 1.f);
	sunlight->SetDiffuse(0.f, 0.f, 0.f, 1.f);
	sunlight->SetSpecular(0.f, 0.f, 0.f, 1.f);

	AddObjectToScene(sunlight);

	auto light1 = new Light(GL_LIGHT1, -575.f, 0.f, 70.f);
	light1->SetAmbience(1.f, 1.f, 1.f, 1.f);
	light1->SetDiffuse(0.8f, 0.8f, 0.8f, 1.f);
	light1->SetSpecular(1.f, 1.f, 1.f, 1.f);

	AddObjectToScene(light1);
}
