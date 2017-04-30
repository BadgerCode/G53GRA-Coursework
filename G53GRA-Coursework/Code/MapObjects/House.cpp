#include "House.h"

House::House()
{
	_size[0] = 1000.f;
	_size[1] = 200.f;
	_size[2] = 750.f;

	_wallThickness = 10.f;

	position(0.f, 100.f, 0.f);
	
	BuildLeftWall();
	BuildRightWall();
	BuildBackWall();
	BuildFrontWall();
}

void House::Display()
{
	glPushMatrix();
	glTranslatef(pos[0], pos[1], pos[2]);

	for (auto wall : _leftWallPieces)
	{
		wall->Display();
	}
	for (auto wall : _rightWallPieces)
	{
		wall->Display();
	}

	for (auto wall : _backWallPieces)
	{
		wall->Display();
	}

	for (auto wall : _frontWallPieces)
	{
		wall->Display();
	}

	glPopMatrix();
}

void House::BuildLeftWall()
{
	float wallSize[3] = { _wallThickness, _size[1], _size[2] + _wallThickness * 2 };
	float wallPieceSize[3] = { _wallThickness, _size[1], wallSize[2] / 3 };
	float backWallSize[3] = { _size[0], _size[1], _wallThickness };

	float wallPos[3] = {
		-backWallSize[0] / 2 - wallSize[0] / 2,
		0.f,
		wallSize[2] / 2 - wallPieceSize[2] / 2
	};

	for(int i = 0; i < 3; i++)
	{
		auto wall = new Cube(wallPos, wallPieceSize);
		wall->SetTexture("./Textures/wood.bmp");
		_leftWallPieces.push_back(wall);

		wallPos[2] -= wallPieceSize[2];
	}
}

void House::BuildRightWall()
{
	float wallSize[3] = { _wallThickness, _size[1], _size[2] + _wallThickness * 2 };
	float wallPieceSize[3] = { _wallThickness, _size[1], wallSize[2] / 3 };
	float backWallSize[3] = { _size[0], _size[1], _wallThickness };

	float wallPos[3] = {
		backWallSize[0] / 2 + wallSize[0] / 2,
		0.f,
		wallSize[2] / 2 - wallPieceSize[2] / 2
	};

	for (int i = 0; i < 3; i++)
	{
		auto wall = new Cube(wallPos, wallPieceSize);
		wall->SetTexture("./Textures/wood.bmp");
		_rightWallPieces.push_back(wall);

		wallPos[2] -= wallPieceSize[2];
	}
}

void House::BuildBackWall()
{
	int wallPieces = 4;
	float wallPieceSize[3] = { _size[0] / wallPieces, _size[1], _wallThickness };

	float wallPos[3] = {
		-_size[0] / 2 + wallPieceSize[0] / 2,
		0.f,
		-_size[2] / 2 - _wallThickness / 2
	};

	for (int i = 0; i < wallPieces; i++)
	{
		auto wall = new Cube(wallPos, wallPieceSize);
		wall->SetTexture("./Textures/wood.bmp");
		_backWallPieces.push_back(wall);

		wallPos[0] += wallPieceSize[0];
	}
}

void House::BuildFrontWall()
{
	int wallPieces = 4;
	float doorSize = 80.f;
	float wallPieceSize[3] = { (_size[0] - doorSize) / wallPieces, _size[1], _wallThickness };

	float wallPos[3] = {
		-_size[0] / 2 + wallPieceSize[0] / 2,
		0.f,
		_size[2] / 2 + _wallThickness / 2
	};

	for (int i = 0; i < wallPieces; i++)
	{
		if (i == 2)
		{
			float doorFrameTopSize[3] = { doorSize, 40.f, _wallThickness };

			wallPos[0] -= wallPieceSize[0] / 2 - doorSize/2;
			wallPos[1] = _size[1] / 2 - doorFrameTopSize[1] / 2;

			auto wall = new Cube(wallPos, doorFrameTopSize);
			wall->SetTexture("./Textures/wood.bmp");
			_backWallPieces.push_back(wall);

			wallPos[0] += doorSize / 2 + wallPieceSize[0] / 2;
			wallPos[1] = 0.f;
		}

		auto wall = new Cube(wallPos, wallPieceSize);
		wall->SetTexture("./Textures/wood.bmp");
		_backWallPieces.push_back(wall);

		wallPos[0] += wallPieceSize[0];
	}
}

void House::BuildDoorFrame()
{

}
