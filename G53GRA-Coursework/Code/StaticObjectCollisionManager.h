#pragma once
#include <vector>
#include "CollisionCube.h"


class StaticObjectCollisionManager
{
public:
	static void AddCollisionCube(float centerPos[], float size[]);
	static float* RestrainMovement(float currentPos[], float direction[], float size[]);
private:
	static std::vector<CollisionCube*> _collisionCubes;
};

