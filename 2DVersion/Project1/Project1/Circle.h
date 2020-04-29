#ifndef Circle_h
#define Circle_h
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(int width, int height,  int row, int column) : Shape(width, height, row, column) {}
	void setLocation(int row, int column);
	virtual void draw();
};

#endif