#pragma once

class CollisionCube
{
public:
	CollisionCube(float centerPos[], float size[])
	{
		minX = centerPos[0] - size[0] / 2;
		maxX = centerPos[0] + size[0] / 2;
		minY = centerPos[1] - size[1] / 2;
		maxY = centerPos[1] + size[1] / 2;
		minZ = centerPos[2] - size[2] / 2;
		maxZ = centerPos[2] + size[2] / 2;
	}

	float minX;
	float maxX;
	float minY;
	float maxY;
	float minZ;
	float maxZ;
};