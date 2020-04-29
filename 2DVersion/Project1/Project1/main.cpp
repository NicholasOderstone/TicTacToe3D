#include<stdlib.h>
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


//main function of the program
int main(int argc, char **argv)
{
	
const int width = 600;
const int height = 650;
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(width,height);
	
	glutCreateWindow("Tic Tac Toe");
	scene = new Scene(width, height);
	initgame();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(KeyPress);
	glutMouseFunc(click);
	glutIdleFunc(display);
    glutMainLoop();

	//delete scene;

	return 0;
}