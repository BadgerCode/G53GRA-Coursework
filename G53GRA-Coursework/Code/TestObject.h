#pragma once

#include "DisplayableObject.h"

class TestObject : public DisplayableObject
{
public:
	TestObject();
	void Display() override;
};