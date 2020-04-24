#ifndef Cross_h
#define Cross_h
#include "Shape.h"

class Cross : public Shape
{
public:
	Cross(int width, int height,  int row, int column) : Shape( width, height, row, column) {}
	void setLocation(int row, int column);
	virtual void draw();
};

#endif