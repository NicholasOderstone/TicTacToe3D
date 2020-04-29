#include <gl\glut.h>
#include "Cross.h"


void Cross::draw()
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
		glVertex2f(column*(height/3) + (height/12), row*(height/3) + (height/12) + 50);
		glVertex2f(column*(height/3) + (height/4), row*(height/3) + (height/4) + 50);

		glVertex2f(column*(height/3) + (height/4), row*(height/3) + (height/12) + 50);
		glVertex2f(column*(height/3) + (height/12), row*(height/3) + (height/4) + 50);
	glEnd();
	
/*
	GLUquadricObj *p = gluNewQuadric();
	gluQuadricDrawStyle(p, GLU_LINE);
	glPushMatrix();
	glTranslatef(column*200 + 100, row*200 + 150, 0);
	gluCylinder(p, 20, 20, 20, 20, 20);
	glRotated(45, 1,0,0);
	glPopMatrix();
	gluDeleteQuadric(p);
*/
}
