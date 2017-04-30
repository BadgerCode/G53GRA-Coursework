#pragma once
#include "DisplayableObject.h"
#include "Cube.h"

class House : public DisplayableObject
{
public:
	House();
	void Display() override;
private:
	float _size[3];
	float _wallThickness;

	std::vector<Cube*> _leftWallPieces;
	std::vector<Cube*> _rightWallPieces;
	std::vector<Cube*> _backWallPieces;
	std::vector<Cube*> _frontWallPieces;

	void BuildLeftWall();
	void BuildRightWall();
	void BuildBackWall();
	void BuildFrontWall();
};
