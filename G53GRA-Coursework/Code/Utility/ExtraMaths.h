#pragma once

#include "VectorMath.h"

inline double degreesToRadians(double degrees)
{
	return (degrees / 180) * static_cast<double>(M_PI);
}