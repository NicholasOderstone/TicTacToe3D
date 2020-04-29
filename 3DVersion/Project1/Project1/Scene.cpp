#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <gl/glut.h>
#include "Board.h"
#include "Cross.h"
#include "Circle.h"
#include "Scene.h"
#include "utils.h"


using namespace GraphUtils;
Scene::Scene(int width, int height)
{
	this->width = width;
	this->height = height;

	distZ = -2;
	angleX = -20;
	angleY = 5;

	shapes.push_back(new Board(diffGray, ambiGray, specGray));
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
	time = 0;

	//clear the matrix
	for(int i = 0; i <= 2; i++)
	{
		for(int j = 0; j <= 2; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void Scene::createObj(int c, int r)
{
	if(gameover == false)
	{
		if(matrix[c][r] == 0)
				{
					if(playerturn == 1)
					{
						matrix[c][r] = 1;
						shapes.push_back(new Cross(0.02, 0.28, diffRed, ambiRed, specRed, 0.06, c, r));
						playerturn = 2;
					}
					else
					{
						matrix[c][r] = 2;
						shapes.push_back(new  Circle(0.25, 0.03, diffBlue, ambiBlue, specBlue, 0.1, c, r));
						playerturn = 1;
					}
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
			break;
		
		case 49:      // Numpad 1
			createObj(2, 0);
			break;
		case 50:      // Numpad 2
			createObj(2, 1);
			break;
		case 51:      // Numpad 3
			createObj(2, 2);
			break;
		case 52:      // Numpad 4
			createObj(1, 0);
			break;
		case 53:      // Numpad 5
			createObj(1, 1);
			break;
		case 54:      // Numpad 6
			createObj(1, 2);
			break;
		case 55:      // Numpad 7
			createObj(0, 0);
			break;
		case 56:      // Numpad 8
			createObj(0, 1);
			break;
		case 57:       // Numpad 9
			createObj(0, 2);
			break;
		default: 
			break;
            
	} 
}

void Scene::special(int key, int x, int y)
    {
        switch (key) {
        case GLUT_KEY_UP:   // наближення
            if (distZ > -1.7)
            {
                break;
            }
            distZ += 0.1;
            break;
        case GLUT_KEY_DOWN: // віддалення
            distZ -= 0.1;
            break;
        case GLUT_KEY_F2:   // нова гра
            initgame();
            break;
        }
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
	// Встановлюємо область перегляду таку, щоб вона вміщувала все вікно:
        glViewport(0, 0, width, height);

        // Ініціалізуємо параметри матеріалів і джерела світла:
        float lightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // колір фонового освітлення 
        float lightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // колір дифузного освітлення 
        float lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };// колір дзеркального відображення
        float lightPosition[] = { 0.0f, 2.0f, 3.0f, 0.0f };// розташування джерела світла

        // Встановлюємо параметри джерела світла:
        glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	// визначаємо блакитний колір для очищення:
        // Визначаємо блакитний колір для очищення:
		if (gameover)
        {
            glClearColor(0, 0.7, 0.7, 0);
        }
        else
        {
            glClearColor(0, 0.5, 0.5, 0);
        }

        // Очищуємо буфери:
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
///////////////////////////////  Text  ///////////////////////////////
		char text[128];

        // Для відображення тексту,
		// краще використовувати ортографічну проекцію:
        glOrtho(0, 1, 0, 1, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glColor3f(1, 1, 0); // жовтий текст
		if (gameover)
        {
			if(result == 0)
			sprintf(text, "Game over!         It`s a draw!           Time: %d sec.", time);
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, text, 0.08, 0.95);
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Do you want to continue (y/n)", 0.25, 0.85);

			if(result == 1)
			sprintf(text, "Game over!        Player 1 wins!          Time: %d sec.", time);
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, text, 0.08, 0.95);
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Do you want to continue (y/n)", 0.25, 0.85);
		
			if(result == 2)
			sprintf(text, "Game over!        Player 2 wins!          Time: %d sec.", time);
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, text, 0.08, 0.95);
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Do you want to continue (y/n)", 0.25, 0.85);
		
			
        }
        else
        {
			sprintf(text, "F2 - Restart game   Esc - Exit              Time: %d sec.", time);
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, text, 0.01, 0.95);
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, "Use your Numpad to draw Cross or Circle", 0.01, 0.9);
            
        }
        glPopMatrix();

        // Включаємо режим роботи з матрицею проекцій:
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

///////////////////////////////////////////////////////////////////////////////////////////////////////
		// Задаємо усічений конус видимості в лівосторонній системі координат, 
        // 60 - кут видимості в градусах по осі у,
        // width/height - кут видимості уздовж осі x,
        // 1 и 100 - відстань від спостерігача до площин відсікання по глибині:
        gluPerspective(60, width / height, 1, 100);

        // Включаємо режим роботи з видовою матрицею:
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

/////////////////////////////////////////////////////////////////////////////////

		// Включаємо режим роботи з видовою матрицею:
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0, 0, distZ);	// камера з початку координат зсувається на distZ, 

        glRotatef(angleX, 0.0f, 1.0f, 0.0f);  // потім обертається по осі Oy
        glRotatef(angleY, 1.0f, 0.0f, 0.0f);  // потім обертається по осі Ox
        glEnable(GL_DEPTH_TEST);	// включаємо буфер глибини (для відсікання невидимих частин зображення)

                                    // Включаємо режим для установки освітлення:
        glEnable(GL_LIGHTING);

        // Додаємо джерело світла № 0 (їх може бути до 8), зараз воно світить з "очей":
        glEnable(GL_LIGHT0);

/////////////////////////////////////////////////////////////////////////////////////////////////////////
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
    
////////////////////////////  Draw //////////////////////////// 

	for (int i = 0; i < shapes.size(); i++)
    {
        shapes[i]->draw();
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		// Вимикаємо все, що включили:
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH_TEST);
        glFlush();
        // показуємо очищене вікно:
        glutSwapBuffers();

		//angleX += 0.3;
		//angleY += 0.1;

}

//This function is called on windows resize
void Scene::reshape(int x, int y)
{
	x = width;
	y = height;
	glutReshapeWindow(x, y);
	glViewport(0, 0, x, y);
	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, x, y, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	*/
}

int tick = 0; // лічильник, значення якого змінюється кожні 25 мс

                  // Оброблювач події від таймера
void Scene::timer(int value)
{
	tick++;
	if (tick >= 40) // нарахували наступну секунду
	{
		if (!gameover)// секунди нарощуються, якщо гру не закінчено
		{
			time++;
		}
		tick = 0;   // скинули лічильник
	}
	display();
}

Scene::~Scene(void)
{
}
