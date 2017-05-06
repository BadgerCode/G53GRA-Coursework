#pragma once

#include "Utility/GlutDependency.h"

class LightManager
{
public:
	static GLenum AllocateLightNumber();
private:
	static int _lightsCount;
};
