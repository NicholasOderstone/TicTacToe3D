#ifndef Shape_h
#define Shape_h


class Shape
{
public:
	float xSize, ySize;
	float *diffColor, *ambiColor, *specColor;
	float boardX;
	float boardY;
	float boardZ;

	Shape(float xSize, float ySize,
		  float *diffColor, float *ambiColor, float *specColor);
	virtual void draw() = 0;
	virtual ~Shape() { } 
};

#endif