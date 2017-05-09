#pragma once
#include "DisplayableObject.h"
#include "ObjectModel.h"

class Object : public DisplayableObject
{
public:
	Object(ObjectModel* model);

	void Display() override;
private:
	ObjectModel* _model;
};
