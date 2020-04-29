#include <gl\glut.h>
#include "Board.h"
#include "utils.h"

void Board::draw()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambiColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specColor);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, GraphUtils::shininess);


	GraphUtils::parallelepiped(xSize, ySize, zSize);
		glLineWidth(5);
		glBegin(GL_LINES);
		glVertex3f(-xSize/2 + xSize/3,  ySize/2, zSize/2 + 0.01);
			glVertex3f(-xSize/2 + xSize/3, -ySize/2, zSize/2 + 0.01);

			glVertex3f(xSize/2 - xSize/3,  ySize/2, zSize/2 + 0.01);
			glVertex3f(xSize/2 - xSize/3, -ySize/2, zSize/2 + 0.01);

			glVertex3f(-xSize/2, ySize/2 - ySize/3, zSize/2 + 0.01);
			glVertex3f( xSize/2, ySize/2 - ySize/3, zSize/2 + 0.01);

			glVertex3f(-xSize/2, -ySize/2 + ySize/3, zSize/2 + 0.01);
			glVertex3f( xSize/2, -ySize/2 + ySize/3, zSize/2 + 0.01);
		glEnd();
	
}
