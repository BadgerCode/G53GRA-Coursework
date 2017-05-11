#pragma once

class CollisionCube
{
public:
	CollisionCube(float* minPos, float* maxPos)
	{
		minX = minPos[0];
		minY = minPos[1];
		minZ = minPos[2];
		maxX = maxPos[0];
		maxY = maxPos[1];
		maxZ = maxPos[2];
	}

	CollisionCube(std::vector<float> minPos, std::vector<float> maxPos)
	{
		minX = minPos[0];
		minY = minPos[1];
		minZ = minPos[2];
		maxX = maxPos[0];
		maxY = maxPos[1];
		maxZ = maxPos[2];
	}

	float minX;
	float maxX;
	float minY;
	float maxY;
	float minZ;
	float maxZ;
};