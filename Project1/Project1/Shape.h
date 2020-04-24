#ifndef Shape_h
#define Shape_h


class Shape
{
public:
	int width;
	int height;
	int row;
	int column;

	Shape(int width, int height);
	Shape(int width, int height,  int row, int column);
	void setParam(int width, int height);
	virtual void draw() = 0;
};

#endif