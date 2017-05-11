#include "MyScene.h"
#include "Services/Materials.h"
#include "Map/Map.h"
#include "Lighting/LightManager.h"

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
	glEnable(GL_LIGHTING);

	_flashlightNumber = LightManager::AllocateLightNumber();

	glLightfv(_flashlightNumber, GL_AMBIENT, new GLfloat[4] { 1.f, 1.f, 1.f, 1.0 });
	glLightfv(_flashlightNumber, GL_DIFFUSE, new GLfloat[4] { 1.f, 1.f, 1.f, 1.0 });
	glLightfv(_flashlightNumber, GL_POSITION, new GLfloat[4] { 0.f, 0.f, 0.f, 1.0 });
	glLightfv(_flashlightNumber, GL_SPOT_DIRECTION, new GLfloat[3]{ 0.f, 0.f, -1.f });
	glLightf(_flashlightNumber, GL_QUADRATIC_ATTENUATION, 0.00005f);
	glLightf(_flashlightNumber, GL_SPOT_CUTOFF, 45.f);
	glLightf(_flashlightNumber, GL_SPOT_EXPONENT, 10.f);

	glEnable(_flashlightNumber);
}

void MyScene::HandleKey(unsigned char key, int state, int x, int y)
{
	Scene::HandleKey(key, state, x, y);

	if(key == 'f' && state == 0)
	{
		if(_flashlightEnabled)
		{
			glDisable(_flashlightNumber);
		}
		else
		{
			glEnable(_flashlightNumber);
		}

		_flashlightEnabled = !_flashlightEnabled;
	}
}
