#ifndef Circle_h
#define Circle_h
#include "Shape.h"

class Circle : public Shape
{
private:
	float innerRadius;
	int column, row;
	GLUquadricObj* quadricObj;
public:
	Circle(float xSize, float ySize,
		  float *diffColor, float *ambiColor, float *specColor,
		  float innerRadius, int row, int column) : Shape(xSize, ySize,
		  diffColor, ambiColor, specColor)
	{
		this->innerRadius = innerRadius;
		this->column = column;
		this->row = row;
	}
	virtual void draw();
	~Circle()
	{
		gluDeleteQuadric(quadricObj);
	}
};

#endif