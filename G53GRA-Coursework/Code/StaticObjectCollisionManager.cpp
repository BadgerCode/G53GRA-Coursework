#include "StaticObjectCollisionManager.h"

std::vector<CollisionCube*> StaticObjectCollisionManager::_collisionCubes;

void StaticObjectCollisionManager::AddCollisionCube(std::vector<float> minPos, std::vector<float> maxPos)
{
	_collisionCubes.push_back(new CollisionCube(minPos, maxPos));
}

float* StaticObjectCollisionManager::RestrainMovement(float currentPos[], float velocity[], float size[])
{
	bool cancelVelocity[3] = { false, false, false };
	int direction[3] = { 
		velocity[0] < 0 ? -1 : 1,
		velocity[1] < 0 ? -1 : 1,
		velocity[2] < 0 ? -1 : 1,
	};

	float x = currentPos[0] + velocity[0];
	float y = currentPos[1] + velocity[1];
	float z = currentPos[2] + velocity[2];

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
			int reverseDirection[3] = {
				(maxX - cube->maxX) < 0 ? -1 : 1,
				(maxY - cube->maxY) < 0 ? -1 : 1,
				(maxZ - cube->maxZ) < 0 ? -1 : 1,
			};

			cancelVelocity[0] = direction[0] != reverseDirection[0] || cancelVelocity[0];
			cancelVelocity[1] = direction[1] != reverseDirection[1] || cancelVelocity[1];
			cancelVelocity[2] = direction[2] != reverseDirection[2] || cancelVelocity[2];
		}
	}

	if (cancelVelocity[0]) x -= velocity[0];
	if (cancelVelocity[1]) y -= velocity[1];
	if (cancelVelocity[2]) z -= velocity[2];

	return new float[3]{ x, y, z};
}
