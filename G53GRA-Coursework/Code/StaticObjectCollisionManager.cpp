#include "StaticObjectCollisionManager.h"

std::vector<CollisionCube*> StaticObjectCollisionManager::_collisionCubes;

void StaticObjectCollisionManager::AddCollisionCube(std::vector<float> minPos, std::vector<float> maxPos)
{
	_collisionCubes.push_back(new CollisionCube(minPos, maxPos));
}

float* StaticObjectCollisionManager::RestrainMovement(float currentPos[], float direction[], float size[])
{
	float x = currentPos[0] + direction[0];
	float y = currentPos[1] + direction[1];
	float z = currentPos[2] + direction[2];

	float minX = x - size[0] / 2;
	float maxX = x + size[0] / 2;
	float minY = y - size[1] / 2;
	float maxY = y + size[1] / 2;
	float minZ = z - size[2] / 2;
	float maxZ = z + size[2] / 2;

	for (CollisionCube* cube : _collisionCubes)
	{
		if((minX <= cube->maxX && maxX >= cube->minX)
			&& (minY <= cube->maxY && maxY >= cube->minY)
			&& (minZ <= cube->maxZ && maxZ >= cube->minZ))
		{
			return currentPos;
		}
	}
	return new float[3]{ x, y, z};
}
