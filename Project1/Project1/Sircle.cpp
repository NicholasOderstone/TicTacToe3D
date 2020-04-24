#include <gl\glut.h>
#include "Sircle.h"

void Sircle::draw()
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
	
	glBegin(GL_LINES);
	glColor3ub(0, 0, 0);
        glVertex2f(50 + column * (height/3) - 25, 100 + row * (height/3) - 25);
        glVertex2f(50 + column * (height/3) + 25, 100 + row * (height/3) + 25);
        glVertex2f(50 + column * (height/3) - 25, 100 + row * (height/3) + 25);
		glVertex2f(50 + column * (height/3) + 25, 100 + row * (height/3) - 25);
	glEnd();
		
}
