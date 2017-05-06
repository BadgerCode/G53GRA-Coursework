#pragma once

#include "Services/GlutDependency.h"

class LightManager
{
public:
	static GLenum AllocateLightNumber();
private:
	static int _lightsCount;
};
