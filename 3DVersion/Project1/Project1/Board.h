#ifndef Board_h
#define Board_h
#include "Shape.h"




class Board :public Shape
{
private:
	float zSize;
public:
	Board(float *diffColor, float *ambiColor, float *specColor) : Shape(xSize, ySize, diffColor, ambiColor, specColor)
	{
		this->xSize = boardX;
		this->ySize = boardY;
		this->zSize = boardZ; 
	}
	virtual void draw(); 
};

#endif