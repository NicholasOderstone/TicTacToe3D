#include <gl\glut.h>
#include "Circle.h"
#include <math.h>
void Circle::draw()
{
	if(width != height)
	{
		if((width - height) < 0)
		{
			height = width;
		}
		else
		{
			width = height;
		}
	}
	/*
	glBegin(GL_LINE_LOOP);
	glColor3ub(0, 0, 0);
        glVertex2f(column*(height/3) + (height/12), row*(height/3) + (height/12) + 50);
		glVertex2f(column*(height/3) + (height/4), row*(height/3) + (height/12) + 50);

		glVertex2f(column*(height/3) + (height/4), row*(height/3) + (height/4) + 50);
		glVertex2f(column*(height/3) + (height/12), row*(height/3) + (height/4) + 50);
	glEnd();
	
	*/
	float r = 60;
	int num_segments = 40;
	float cx = column*(height/3) + (height/6);
	float cy = row*(height/3) + (height/6) + 50;
	glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
        float x = r * cosf(theta);//calculate the x component 
        float y = r * sinf(theta);//calculate the y component 
        glVertex2f(x + cx, y + cy);//outputs vertex 
    }
    glEnd();
	
}
