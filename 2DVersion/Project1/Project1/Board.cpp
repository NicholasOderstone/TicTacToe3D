#include <gl\glut.h>
#include "Board.h"


void Board::draw()
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
		glVertex3f(width/3, 50, 0);
		glVertex3f(width/3, height+50, 0);

		glVertex3f(2*width/3, 50, 0);
		glVertex3f(2*width/3, height+50, 0);

		glVertex3f(0, height/3 +50, 0);
		glVertex3f(width, height/3 +50, 0);

		glVertex3f(0, 2*height/3 +50, 0);
		glVertex3f(width, 2*height/3 +50, 0);
	glEnd();
	
}
