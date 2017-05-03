#pragma once
#include <fstream>

class ModelBuilder
{
public:
	static void Build();
};

inline void ModelBuilder::Build()
{
	std::ofstream fileStream("./Code/Data/Models/Map/Floor.obj", std::ios_base::out);

	if (!fileStream)
	{
		printf("Model builder: error opening file.\n");
		return;
	}

	fileStream.precision(4);
	fileStream << std::fixed;

	int tileSize = 100.f;
	int numRowsOrCols = 10000 / tileSize;
	for(float i = 0; i < numRowsOrCols + 1; i++)
	{
		for(float j = 0; j < numRowsOrCols + 1; j++)
		{
			auto x = tileSize * i - 5000;
			auto z = tileSize * j - 5000;

			fileStream << "v " << x << " 0.0000 " << z << std::endl;
		}
	}

	fileStream << "vt 0.0 0.0" << std::endl;
	fileStream << "vt 0.0 1.0" << std::endl;
	fileStream << "vt 1.0 0.0" << std::endl;
	fileStream << "vt 1.0 1.0" << std::endl;
	fileStream << "vn 0.0 1.0 0.0" << std::endl;
	fileStream << "usemtl material_grass" << std::endl;

	for (int x = 0; x < numRowsOrCols; x++)
	{
		for (int z = 0; z < numRowsOrCols; z++)
		{
			auto topLeft = x * numRowsOrCols + z + 1;
			auto bottomLeft = topLeft + 1;
			auto topRight = topLeft + numRowsOrCols + 1;
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
