#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<gl/glut.h>
#include "Scene.h"


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

//Used to write text in the opengl window
void drawString (void * font, char *s, float x, float y){
    unsigned int i;
    glRasterPos2f(x, y);
    for (i = 0; i < strlen (s); i++)
        glutBitmapCharacter (font, s[i]);
}

//main function of the program
int main(int argc, char **argv)
{
	
const int width = 300;
const int height = 350;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(width,height);
	glOrtho(0, width, height, 0, 0, 1);
	glutCreateWindow("Tic Tac Toe");
	scene = new Scene(width, height);
	initgame();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(KeyPress);
	glutMouseFunc(click);
	glutIdleFunc(display);
    glutMainLoop();

	delete scene;

	return 0;
}