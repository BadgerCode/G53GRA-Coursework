#include "StaticObjectCollisionManager.h"

std::vector<CollisionSphere*> StaticObjectCollisionManager::_collisionSpheres;

void StaticObjectCollisionManager::AddCollisionSphere(float x, float y, float z, float radius)
{
	auto collisionSphere = new CollisionSphere(x, y, z, radius);
	_collisionSpheres.push_back(collisionSphere);
}

bool StaticObjectCollisionManager::CheckPlayerForCollision(float x, float y, float z)
{
	for (CollisionSphere* sphere : _collisionSpheres)
	{
		float distance = sqrt(pow((sphere->x - x), 2) + pow(sphere->y - y, 2) + pow(sphere->z - z, 2));
		if(distance < sphere->radius)
		{
			return true;
		}
	}
	return false;
}
