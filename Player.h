#pragma once
#include "Point.h"

#define MAX_FRAME_FOR_X 119
#define MAX_FRAME_FOR_Y 29
#define MAX_SNAKE 100

class Player
{
private:
	Point* cell[MAX_SNAKE];
	Point fruit;
	char direc; //the direction of the player
	int size; //size of the plire
	int state; //is alive or dead?
	int started;
	int fruitBlink; //for the fruit
public:
	Player(); //Ctor.

	void addCell(int xVal, int yVal); //make the player bigger.

	//direction of the player on screen.
	void playerUp(); // w is up
	void playerDown(); // s is down
	void playerRight(); //d is right
	void playerLeft(); // a is left

	int selfColi(); //bitting his own body.

	//MOVEMENT!
	void playerMove();
	
};

