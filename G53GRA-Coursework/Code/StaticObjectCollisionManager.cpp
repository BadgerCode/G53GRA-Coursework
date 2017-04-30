#include "StaticObjectCollisionManager.h"

std::vector<CollisionSphere*> StaticObjectCollisionManager::_collisionSpheres;

void StaticObjectCollisionManager::AddCollisionSphere(float x, float y, float z, float radius)
{
	auto collisionSphere = new CollisionSphere(x, y, z, radius);
	_collisionSpheres.push_back(collisionSphere);
}

void StaticObjectCollisionManager::Update(const double& deltaTime)
{
	float x, y, z, dx, dy, dz;
	Scene::GetCamera()->GetEyePosition(x, y, z);
	Scene::GetCamera()->GetViewDirection(dx, dy, dz);

}

void StaticObjectCollisionManager::Display()
{
}
