#include <gl\glut.h>
#include "Circle.h"
#include "utils.h"

void Circle::draw()
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambiColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specColor);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, GraphUtils::shininess);

	float xCenter = -boardX/3 + column*(boardX/3);
	float yCenter = boardY/3 - row*(boardY/3);
	float zCenter = boardZ/2 + ySize/2;

	glPushMatrix();
        glTranslatef(xCenter, yCenter + ySize / 2, zCenter);
        // Циліндр повинен бути розташований у вертикальному напрямку:
        quadricObj = gluNewQuadric();
        gluCylinder(quadricObj, xSize / 2, xSize / 2, ySize, 20, 2);
        // Диск повинен бути намальований зовнішньою гранню догори:
        glRotatef(180, 1, 0, 0);
        // Малюємо диск зверху:
        gluDisk(quadricObj, innerRadius, xSize / 2, 20, 20);
        // Малюємо диск знизу:
        glTranslatef(0, 0, -ySize);
        gluDisk(quadricObj, innerRadius, xSize / 2, 20, 20);
        
        // Відновлення поточної матриці зі стека:
        glPopMatrix();
	
}
