#pragma once
#include <vector>
#include "CollisionSphere.h"
#include "Animation.h"
#include "DisplayableObject.h"


class StaticObjectCollisionManager : public DisplayableObject, public Animation
{
public:
	StaticObjectCollisionManager() {  }
	static void AddCollisionSphere(float x, float y, float z, float radius);
	void Update(const double& deltaTime) override;

	void Display() override;
private:
	static std::vector<CollisionSphere*> _collisionSpheres;
};

