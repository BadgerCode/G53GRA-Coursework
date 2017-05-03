#pragma once
#include <fstream>

class ModelBuilder
{
public:
	static void Build();
};

inline void ModelBuilder::Build()
{
	std::ofstream fileStream("./Code/Data/Models/Map/HouseFloor.obj", std::ios_base::out);

	if (!fileStream)
	{
		printf("Model builder: error opening file.\n");
		return;
	}

	fileStream.precision(4);
	fileStream << std::fixed;

	float centerX = 0;
	float centerY = 0;
	float width = 1000.f;
	float depth = 750.f;
	int tileSize = 125.f;
	int numRows = depth / tileSize;
	int numCols = width / tileSize;
	for(float i = 0; i < numCols + 1; i++)
	{
		for(float j = 0; j < numRows + 1; j++)
		{
			auto x = tileSize * i - centerX - width / 2;
			auto z = tileSize * j - centerY - depth / 2;

			fileStream << "v " << x << " 0.0000 " << z << std::endl;
		}
	}

	fileStream << "vt 0.0 0.0" << std::endl;
	fileStream << "vt 0.0 1.0" << std::endl;
	fileStream << "vt 1.0 0.0" << std::endl;
	fileStream << "vt 1.0 1.0" << std::endl;
	fileStream << "vn 0.0 1.0 0.0" << std::endl;
	fileStream << "usemtl material_woodfloor" << std::endl;

	for (int x = 0; x < numCols; x++)
	{
		for (int z = 0; z < numRows; z++)
		{
			auto topLeft = x * (numRows+1) + z + 1;
			auto bottomLeft = topLeft + 1;
			auto topRight = topLeft + (numRows + 1);
			auto bottomRight = topRight + 1;

			fileStream << "f "
				<< topLeft << "/2/1 "
				<< bottomLeft << "/1/1 "
				<< bottomRight << "/3/1"
				<< std::endl;

			fileStream << "f "
				<< bottomRight << "/3/1 "
				<< topRight << "/4/1 "
				<< topLeft << "/2/1"
				<< std::endl;
		}
	}

	fileStream.close();
}
