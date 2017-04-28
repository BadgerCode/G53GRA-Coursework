#include "MyScene.h"
#include "TestObject.h"
#include "Skybox.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	AddObjectToScene(new Skybox(5000, "./Textures/skybox-2.bmp"));
	AddObjectToScene(new TestObject());
}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 9000.0);
}
