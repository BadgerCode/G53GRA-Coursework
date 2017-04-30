#pragma once
#include <vector>
#include "CollisionSphere.h"


class StaticObjectCollisionManager
{
public:
	static void AddCollisionSphere(float x, float y, float z, float radius);
	static bool CheckPlayerForCollision(float x, float y, float z);
private:
	static std::vector<CollisionSphere*> _collisionSpheres;
};

