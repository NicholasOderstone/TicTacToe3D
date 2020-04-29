#include "Shape.h"


Shape::Shape(int width, int height)
{
	this->width = width;
	this->height = height;
}
Shape::Shape(int width, int height,  int row, int column)
{
	this->width = width;
	this->height = height;
	this->row = row;
	this->column = column;
}
void Shape::setParam(int width, int height)
{
	this->width = width;
	this->height = height;
}
