#include "Shape.h"


Shape::Shape(float xSize, float ySize,
		  float *diffColor, float *ambiColor, float *specColor)
{
	boardX = 1;
	boardY = 1;
	boardZ = 0.3;
	this->xSize = xSize;
	this->ySize = ySize;

	this->diffColor = diffColor;
	this->ambiColor = ambiColor;
	this->specColor = specColor;
}
