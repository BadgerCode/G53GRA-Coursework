#include "LightManager.h"
#include <cstdio>

int LightManager::_lightsCount;

GLenum LightManager::AllocateLightNumber()
{
	if(_lightsCount >= 8)
	{
		printf("LIGHTING ERROR: Attempted to allocate more than 8 lights.\n");
		return -1;
	}

	return GL_LIGHT0 + _lightsCount++;
}
