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
	AddObjectToScene(new Skybox(GL_LIGHT0, 5000, "./Textures/skybox-2.bmp"));
	AddObjectToScene(new TestObject(0, 0, 0));
	AddObjectToScene(new TestObject(-150, 0, 0));
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 9000.0);
}

void MyScene::SetupLighting()
{
	AddObjectToScene(new Light(GL_LIGHT1, -75, 0, 70));
}
