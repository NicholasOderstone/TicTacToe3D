#include <gl\glut.h>
#include "Cross.h"
#include "utils.h"

void Cross::draw()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambiColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specColor);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, GraphUtils::shininess);

	float xCenter = -boardX/3 + column*(boardX/3);
	float yCenter = boardY/3 - row*(boardY/3);
	float zCenter = boardZ/2;
        // Запис поточної матриці в стек
        // (збереження вмісту поточної матриці для подальшого використання):
	glPushMatrix();
	glTranslatef(xCenter, yCenter, zCenter);
			glRotatef(45, 0, 0, 1);
			GraphUtils::parallelepiped(xSize, ySize, zSize);

			glRotatef(95, 0, 0, 1);
				GraphUtils::parallelepiped(xSize, ySize, zSize);
	glPopMatrix();
}
