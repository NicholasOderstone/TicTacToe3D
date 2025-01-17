#include<math.h>
#include<string.h>
#include <stdlib.h>
#include <iostream>
#include <gl/glut.h>
#include "Board.h"
#include "Cross.h"
#include "Circle.h"
#include "Scene.h"

Scene::Scene(int width, int height)
{
	this->width = width;
	this->height = height;

	shapes.push_back(new Board(width, height));
	initgame();
}
void Scene::initgame()
{
	for (int i = 1; i < shapes.size(); i++)
    {
		shapes.erase(shapes.begin() + 1, shapes.end());
    }
	playerturn = 1; //x starts first
	gameover = false;
	//clear the matrix
	for(int i = 0; i <= 2; i++)
	{
		for(int j = 0; j <= 2; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

//this function is called when keyboard button is pressed 
void Scene::KeyPress(unsigned char key, int x, int y ){
    switch(key){
		case 'y':
			if(gameover == true)
			{
				gameover = false;
				initgame();
			}
			break;
		case 'n':
			if(gameover == true)
				exit(0);
			break;
		case 27:
			exit(0);
            
	} 
}

//This function is called when the mouse button is pressed and this function puts the x or o on the blank box 
void Scene::click(int button, int state, int x, int y)
{
	
	if(gameover == false && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(y < 50)
		{

		}
		else if(playerturn == 1)
		{
			if(matrix[(y - (height/12))/ ((height - (height/12))/3)][x / (width/3)] == 0)
			{
				matrix[(y - (height/12))/ ((height - (height/12))/3)][x / (width/3)] = 1;
				shapes.push_back(new Cross(width, height, (y - (height/12)) / ((height - (height/12))/3), x/(width/3)));
				playerturn = 2;
			}
		}
		else
		{
			if(matrix[(y - (height/12)) / ((height - (height/12))/3)][x / (width/3)] == 0)
			{
				matrix[(y - (height/12))/ ((height - (height/12))/3)][x / (width/3)] = 2;
				shapes.push_back(new Circle(width, height, (y - (height/12)) / ((height - (height/12))/3), x/(width/3)));
				playerturn = 1;
			}
		}
	}
}

//Used to write text in the opengl window
void Scene::drawString (void * font, char *s, float x, float y){
    unsigned int i;
    glRasterPos2f(x, y);
    for (i = 0; i < strlen(s); i++)
        glutBitmapCharacter (font, s[i]);
}

//This function checks if there is any winner
bool Scene::checkifwin()
{
	int i, j;
	// horizontal check
	for(i=0;i<3;i++)
	{
		for(j=1;j<3;j++)
		{
			if(matrix[i][0]!=0 && matrix[i][0]==matrix[i][j])
			{
				if(j==2)
				{
					return true;
				}
			}
			else
				break;
		}
	}
	// vertical check
	for(i=0;i<3;i++)
	{
		for(j=1;j<3;j++)
		{
			if(matrix[0][i]!=0 && matrix[0][i]==matrix[j][i])
			{
				if(j==2)
					return true;
			}
			else
				break;
		}
	}
	// Diagonal check
	if((matrix[0][0]!=0 && matrix[0][0]==matrix[1][1] && matrix[0][0]==matrix[2][2]) 
	|| (matrix[2][0]!=0 && matrix[2][0]==matrix[1][1] && matrix[2][0]==matrix[0][2]))
		return true;
	return false;
}

//This function checks if the match is a draw i.e it returns false if there is atleast one empty box else returns true 
bool Scene::checkifdraw()
{
	int i, j;
    
	for(i = 0; i <= 2; i++)
	{ 
		for(j = 0; j <= 2; j++)
		{ 
			if(matrix[i][j] == 0)
				return false;
		}
	}
	return true;	
}

void Scene::display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1, 1, 1, 1);
	glColor3f(0, 0, 0);
	if(playerturn == 1)
		drawString(GLUT_BITMAP_HELVETICA_18, "Player1's turn", height/3 + 30, 30);	
	else
		drawString(GLUT_BITMAP_HELVETICA_18, "Player2's turn", height/3 + 30, 30);	
	if(checkifwin() == true)
	{
		//the player who made the previous move is the winner
		if(playerturn == 1)
		{
			gameover = true;
			result = 2; //player2 wins
		}
		else
		{
			gameover = true;
			result = 1; //player1 wins
		}
	}
	else if(checkifdraw() == true)
	{
		gameover = true;
		result = 0;
	}
    
	if(gameover == true)
	{
		drawString(GLUT_BITMAP_HELVETICA_18, "Game Over", height/3 + 30, 160);
		
		if(result == 0)
			drawString(GLUT_BITMAP_HELVETICA_18, "Its a draw", height/3 + 40, 185);
		
		if(result == 1)
			drawString(GLUT_BITMAP_HELVETICA_18, "Player1 wins", height/3 + 25, 185);
		
		if(result == 2)
			drawString(GLUT_BITMAP_HELVETICA_18, "Player2 wins", height/3 + 25, 185);
		
		drawString(GLUT_BITMAP_HELVETICA_18, "Do you want to continue (y/n)",  height/3 - 30, 210);
	}
    

	for (int i = 0; i < shapes.size(); i++)
    {
        shapes[i]->draw();
    }

	glFlush();
	glutSwapBuffers();
}

//This function is called on windows resize
void Scene::reshape(int x, int y)
{
	x = width;
	y = height;
	glutReshapeWindow(x, y);
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, x, y, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}



Scene::~Scene(void)
{
}
