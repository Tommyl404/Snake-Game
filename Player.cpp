#include "Player.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <time.h>
#include "Point.h"
#pragma warning(disable : 4996)

HANDLE consolee = GetStdHandle(STD_OUTPUT_HANDLE);


Player::Player()
{
	size = 1;
	cell[0] = new Point(20, 20); //where do i start
	for (int i = 1; i < MAX_SNAKE; i++)
		cell[i] = nullptr;
	fruit.SetPoint(rand() % MAX_FRAME_FOR_X, rand() % MAX_FRAME_FOR_Y); //random generator for fruit at start.
	state = 0;
	started = 0;
}

void Player::addCell(int xVal, int yVal)
{
	cell[(size++)] = new Point(xVal, yVal);  //Postfix increment for size.
}

void Player::playerUp()
{
	if (direc != 's')
		direc = 'w';
}

void Player::playerDown()
{
	if (direc != 'w')
		direc = 's';
}

void Player::playerRight()
{
	if (direc != 'a')
		direc = 'd';
}

void Player::playerLeft()
{
	if (direc != 'd')
		direc = 'a';
}

int Player::selfColi()
{
	for (int i = 1; i < size; i++)
		if (cell[0]->isEql(cell[i]))
			return 1;
		return 0;
}

void Player::playerMove()
{
	system("cls");

	if (state == 0)
	{
		if (!started)
		{
			std::cout << "\n\n Press any key to start";
			getch();
			started = 1;
			state = 1;
		}
		else
		{
			std::cout << "\nGAME OVER!";
			std::cout << "\nPress any key to restart";
			getch();
			state = 1;
			size = 1;

		}
	}
	//making the snake follow by the head
	for (int i = (size - 1); i > 0; i--)
		cell[i - 1]->copyPos(cell[i]);

	//turning the head

	switch(direc)
	{
	case 'w':
		cell[0]->moveUp();
		break;
	case 's':
		cell[0]->moveDown();
		break;
	case 'd':
		cell[0]->moveRight();
		break;
	case 'a':
		cell[0]->moveLeft();
		break;
	}

	if (selfColi()) //check if he bit himself from the movement.
		state = 0;

	if (fruit.getX() == cell[0]->getX() && fruit.getY() == cell[0]->getY()) //if player got a fruit
	{
		addCell(0, 0); //make the player grow
		fruit.SetPoint(rand() % MAX_FRAME_FOR_X, rand() % MAX_FRAME_FOR_Y);
	}

	for (int i = 0; i < size; i++) //make the player on screen
		cell[i]->maker();

	SetConsoleTextAttribute(consolee, 242);
	/*if (!fruitBlink)*/
		fruit.maker('#');
	/*fruitBlink = !fruitBlink;*/
	SetConsoleTextAttribute(consolee, 252);

	Sleep(70);
}
