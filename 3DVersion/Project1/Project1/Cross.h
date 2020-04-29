#ifndef Cross_h
#define Cross_h
#include "Shape.h"

class Cross : public Shape
{
private:
	float zSize;
	int column, row;
public:
	Cross(float xSize, float ySize,
		  float *diffColor, float *ambiColor, float *specColor, float zSize, int row, int column) : Shape(xSize, ySize,
		  diffColor, ambiColor, specColor)
	{
		this->zSize = zSize;
		this->column = column;
		this->row = row;
	}
	virtual void draw();
};

#endif