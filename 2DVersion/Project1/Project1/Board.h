#ifndef Board_h
#define Board_h
#include "Shape.h"
class Board :public Shape
{
public:
	Board(int width, int height) : Shape( width, height, row, column) {}
	virtual void draw(); //This function is used to draw the 4 lines 2 vertical and 2 horizontal
};

#endif