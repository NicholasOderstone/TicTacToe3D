#include<stdlib.h>
#include<gl/glut.h>
#include "Scene.h"

/*
Scene* scene;

void click(int button, int state, int x, int y)
{
	scene->click(button, state, x, y);
}

void KeyPress(unsigned char key, int x, int y )
{
	scene->KeyPress(key, x, y);
}

void reshape(int x, int y)
{
	scene->reshape(x, y);
}

void display()
{
	scene->display();
}

void initgame()
{
	scene->initgame();
}
*/

///////////////////////////////////////////////////////////////////////////

	float diffWhite[] = { 1.0f, 1.0f, 1.0f };
    float ambiWhite[] = { 0.8f, 0.8f, 0.8f };
    float specWhite[] = { 1.0f, 1.0f, 1.0f };

    float diffBlue[] = { 0.0f, 0.0f, 0.6f };
    float ambiBlue[] = { 0.1f, 0.1f, 0.2f };
    float specBlue[] = { 0.2f, 0.2f, 0.8f };

    float diffGray[] = { 0.6f, 0.6f, 0.6f };
    float ambiGray[] = { 0.2f, 0.2f, 0.2f };
    float specGray[] = { 0.8f, 0.8f, 0.8f };

    float diffRed[] = { 0.6f, 0.0f, 0.0f };
    float ambiRed[] = { 0.2f, 0.1f, 0.1f };
    float specRed[] = { 0.8f, 0.2f, 0.2f };

    float diffYellow[] = { 0.9f, 0.9f, 0 };
    float ambiYellow[] = { 0.2f, 0.2f, 0.1f };
    float specYellow[] = { 1.0f, 1.0f, 0.2f };

    float diffGreen[] = { 0, 0.5f, 0 };
    float ambiGreen[] = { 0.1f, 0.2f, 0.1f };
    float specGreen[] = { 0.2f, 0.7f, 0.2f };

    float diffOrange[] = { 0.9f, 0.2f, 0 };
    float ambiOrange[] = { 0.2f, 0.2f, 0.2f };
    float specOrange[] = { 0.8f, 0.8f, 0.8f };

    float diffLightBlue[] = { 0, 0.6f, 0.9f };
    float ambiLightBlue[] = { 0.2f, 0.2f, 0.2f };
    float specLightBlue[] = { 0.8f, 0.8f, 0.8f };

    float diffViolet[] = { 0.5f, 0, 0.5f };
    float ambiViolet[] = { 0.2f, 0.2f, 0.2f };
    float specViolet[] = { 0.8f, 0.8f, 0.8f };

	const float shininess = 64;

///////////////////////////////////////////////////////////////////////////
const int width = 600;
const int height = 600;

float boardX = 1;
float boardY = 1;
float boardZ = 0.3;
void parallelepiped(float length, float width, float height)
    {
        glBegin(GL_QUAD_STRIP);
        //����� 1 || YZ, x<0
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(-length / 2, -width / 2, -height / 2);
        glVertex3f(-length / 2, -width / 2, height / 2);
        glVertex3f(-length / 2, width / 2, -height / 2);
        glVertex3f(-length / 2, width / 2, height / 2);

        //����� 2 || ZX, y>0
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(length / 2, width / 2, -height / 2);
        glVertex3f(length / 2, width / 2, height / 2);

        //����� 3 || YZ, x>0
        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(length / 2, -width / 2, -height / 2);
        glVertex3f(length / 2, -width / 2, height / 2);

        //����� 4 || ZX y<0
        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(-length / 2, -width / 2, -height / 2);
        glVertex3f(-length / 2, -width / 2, height / 2);
        glEnd();

        glBegin(GL_QUADS);
        //����� 5 || YX, z>0
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-length / 2, -width / 2, height / 2);
        glVertex3f(-length / 2, width / 2, height / 2);
        glVertex3f(length / 2, width / 2, height / 2);
        glVertex3f(length / 2, -width / 2, height / 2);

        //����� 6  || YX, z<0
        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(-length / 2, -width / 2, -height / 2);
        glVertex3f(-length / 2, width / 2, -height / 2);
        glVertex3f(length / 2, width / 2, -height / 2);
        glVertex3f(length / 2, -width / 2, -height / 2);
        glEnd();
    }

void drawSphere(float radius, int column, int row)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambiOrange);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffOrange);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specOrange);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

	float xCenter = -boardX/3 + column*(boardX/3);
	float yCenter = boardY/3 - row*(boardY/3);
	float zCenter = boardZ/2;

		glPushMatrix();
		glTranslatef(xCenter, yCenter, zCenter);
		GLUquadricObj *sphere = gluNewQuadric();
		gluSphere(sphere, radius, 20, 20);
		glPopMatrix();
}

// Draw Board
void drawBoard(float length, float width, float height)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambiGray);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffGray);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specGray);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);


	parallelepiped(length, width, height);
		glLineWidth(5);
		glBegin(GL_LINES);
		glVertex3f(-length/2 + length/3,  width/2, height/2 + 0.05);
			glVertex3f(-length/2 + length/3, -width/2, height/2 + 0.05);

			glVertex3f(length/2 - length/3,  width/2, height/2 + 0.05);
			glVertex3f(length/2 - length/3, -width/2, height/2 + 0.05);

			glVertex3f(-length/2, width/2 - width/3, height/2 + 0.05);
			glVertex3f( length/2, width/2 - width/3, height/2 + 0.05);

			glVertex3f(-length/2, -width/2 + width/3, height/2 + 0.05);
			glVertex3f( length/2, -width/2 + width/3, height/2 + 0.05);
		glEnd();
}

// Draw Cross
void drawCross(float length, float width, float height, int column, int row)
{

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambiRed);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffRed);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specRed);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

	float xCenter = -boardX/3 + column*(boardX/3);
	float yCenter = boardY/3 - row*(boardY/3);
	float zCenter = boardZ/2;
        // ����� ������� ������� � ����
        // (���������� ����� ������� ������� ��� ���������� ������������):
	glPushMatrix();
	glTranslatef(xCenter, yCenter, zCenter);
			glRotatef(45, 0, 0, 1);
			parallelepiped(length, width, height);

			glRotatef(95, 0, 0, 1);
				parallelepiped(length, width, height);
	glPopMatrix();

}

// Draw Circle
void drawCircle(float xSize, float ySize, float innerRadius, int column, int row)
{

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambiBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffBlue);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specBlue);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

	float xCenter = -boardX/3 + column*(boardX/3);
	float yCenter = boardY/3 - row*(boardY/3);
	float zCenter = boardZ/2 + ySize/2;

	glPushMatrix();
        glTranslatef(xCenter, yCenter + ySize / 2, zCenter);
        // ������ ������� ���� ������������ � ������������� ��������:
        GLUquadricObj* quadricObj = gluNewQuadric();
        gluCylinder(quadricObj, xSize / 2, xSize / 2, ySize, 20, 2);
        // ���� ������� ���� ������������ ��������� ������ ������:
        glRotatef(180, 1, 0, 0);
        // ������� ���� ������:
        gluDisk(quadricObj, innerRadius, xSize / 2, 20, 2);
        // ������� ���� �����:
        glTranslatef(0, 0, -ySize);
        gluDisk(quadricObj, innerRadius, xSize / 2, 20, 2);
        gluDeleteQuadric(quadricObj);
        // ³��������� ������� ������� � �����:
        glPopMatrix();
}


void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 49:      // Numpad 1
		
		break;
	case 50:      // Numpad 2
		
		break;
	case 51:      // Numpad 3
		
		break;
	case 52:      // Numpad 4
		
		break;
	case 53:      // Numpad 5
		
		break;
	case 54:      // Numpad 6
		
		break;
	case 55:      // Numpad 7
		
		break;
	case 56:      // Numpad 8
		
		break;
	case 57:       // Numpad 9
		
		break;
	default: 
		break;
	}
}



float distZ = -2;
float angleX = 0;
float angleY = 0;

void display()
{

	// ������������ ������� ��������� ����, ��� ���� �������� ��� ����:
        glViewport(0, 0, width, height);

        // ���������� ��������� �������� � ������� �����:
        float lightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // ���� �������� ��������� 
        float lightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // ���� ��������� ��������� 
        float lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };// ���� ������������ �����������
        float lightPosition[] = { 0.0f, 2.0f, 3.0f, 0.0f };// ������������ ������� �����

        // ������������ ��������� ������� �����:
        glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	// ��������� ��������� ���� ��� ��������:
        glClearColor(0, 0.5, 0.5, 0);  
        // ������� ������:
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
		// ������ ������� ����� �������� � ����������� ������ ���������, 
        // 60 - ��� �������� � �������� �� �� �,
        // width/height - ��� �������� ������ �� x,
        // 1 � 100 - ������� �� ����������� �� ������ �������� �� ������:
        gluPerspective(60, width / height, 1, 100);

        // �������� ����� ������ � ������� ��������:
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

/////////////////////////////////////////////////////////////////////////////////

		// �������� ����� ������ � ������� ��������:
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0, 0, distZ);	// ������ � ������� ��������� ��������� �� distZ, 

        glRotatef(angleX, 0.0f, 1.0f, 0.0f);  // ���� ���������� �� �� Oy
        glRotatef(angleY, 1.0f, 0.0f, 0.0f);  // ���� ���������� �� �� Ox
        glEnable(GL_DEPTH_TEST);	// �������� ����� ������� (��� �������� ��������� ������ ����������)

                                    // �������� ����� ��� ��������� ���������:
        glEnable(GL_LIGHTING);

        // ������ ������� ����� � 0 (�� ���� ���� �� 8), ����� ���� ������ � "����":
        glEnable(GL_LIGHT0);

/////////////////////////////////////////////////////////////////////////////////////////////////////////

		drawBoard(boardX, boardY, boardZ);
		/*drawSphere(0.15, 0, 0);
		drawSphere(0.15, 0, 1);
		drawSphere(0.15, 0, 2);
		drawSphere(0.15, 1, 0);
		drawSphere(0.15, 1, 1);
		drawSphere(0.15, 1, 2);
		drawSphere(0.15, 2, 0);
		drawSphere(0.15, 2, 1);
		drawSphere(0.15, 2, 2);
		*/
		
		drawCircle(0.25, 0.02, 0.1, 0, 0);
		 drawCross(0.01, 0.28, 0.01, 0, 1);
		drawCircle(0.25, 0.02, 0.1, 0, 2);
		 drawCross(0.01, 0.28, 0.01, 1, 0);
		 drawCross(0.01, 0.28, 0.01, 1, 1);
		 drawCross(0.01, 0.28, 0.01, 1, 2);
		drawCircle(0.25, 0.02, 0.1, 2, 0);
		 drawCross(0.01, 0.28, 0.01, 2, 1);
		drawCircle(0.25, 0.02, 0.1, 2, 2);

		
		


/////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		// �������� ���, �� ��������:
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH_TEST);
        glFlush();
        // �������� ������� ����:
        glutSwapBuffers();

		//angleX += 0.1;
		//angleY += 0.1;
}
//main function of the program
int main(int argc, char **argv)
{
	

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(width,height);
	
	glutCreateWindow("Tic Tac Toe");
	//scene = new Scene(width, height);
	//initgame();
	//glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(processNormalKeys);
	//glutMouseFunc(click);
	glutIdleFunc(display);
    glutMainLoop();

	//delete scene;

	return 0;
}











// ���������� �����������