#ifndef Scene_h
#define Scene_h
#include "Shape.h"
#include "Board.h"
#include "Cross.h"
#include "Circle.h"
#include <vector>

class Scene
{
private:
	int matrix[3][3]; //this matrix stores the x and o and blank box of the game, a value of 0 is blank, 1 is x and 2 is o
	int playerturn; //playerturn if it is 1 then 1st players turn else if it is 2 then its second players turn
	int result; //result of the game if it is 0 then draw if it is 1 then player 1 wins if it is 2 then player 2 wins
	bool gameover; //gameover if it is 0 then its not game over else if it is 1 then its game over
	int time;

	float distZ;
	float angleX;
	float angleY;

	int width, height; // width and height of the window

	std::vector<Shape*> shapes;
	

public:

	Scene(int width, int height);

	void reshape(int x, int y);
	void display();
	void createObj(int c, int r);
	bool checkifdraw();
	bool checkifwin();
	void KeyPress(unsigned char key, int x, int y );
	void special(int key, int x, int y);
	void initgame();
	void timer(int value);

	~Scene(void);
};

#endif