#ifndef Sircle_h
#define Sircle_h
#include "Shape.h"

class Sircle : public Shape
{
public:
	Sircle(int width, int height,  int row, int column) : Shape(width, height, row, column) {}
	void setLocation(int row, int column);
	virtual void draw();
};

#endif