#pragma once

class CollisionSphere
{
public:
	CollisionSphere(float x, float y, float z, float radius) : _x(x), _y(y), _z(z), _radius(radius)
	{

	}

	float _x;
	float _y;
	float _z;
	float _radius;
};