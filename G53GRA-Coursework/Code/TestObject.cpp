#include "TestObject.h"

TestObject::TestObject()
{
	_vertices = { 
		{-1.0, 5.0, 1.0},
		{-1.0, 3.0, 1.0},
		{1.0, 3.0, 1.0}
	};
	_faces = {
		{1, 2, 3}
	};
}

void TestObject::Display()
{

}
