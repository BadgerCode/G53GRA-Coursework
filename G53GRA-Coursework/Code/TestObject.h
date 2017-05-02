#pragma once
#include "DisplayableObject.h"

class TestObject : public DisplayableObject
{
public:
	TestObject();
	void Display() override;
private:
	std::vector<std::vector<float>> _vertices;
	std::vector<std::vector<int>> _faces;
};
