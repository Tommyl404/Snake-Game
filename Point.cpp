#include "Point.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <dos.h>



#define MAX_FRAME_FOR_X 119
#define MAX_FRAME_FOR_Y 29

HANDLE consoleee = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorCoorde;

void goXY(int x, int y) //to make the cursor move.
{
	cursorCoorde.X = x;
	cursorCoorde.Y = y;
	SetConsoleCursorPosition(consoleee, cursorCoorde);
}






Point::Point()
{
	x = 10;
	y = 10;
}

Point::Point(int xVal, int yVal)
{
	this->x = xVal;
	this->y = yVal;
}

void Point::SetPoint(int xVal, int yVal)
{
	this->x = xVal;
	this->y = yVal;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

void Point::moveUp()
{
	y = y - 1;
	if (y < 0)
		y = MAX_FRAME_FOR_Y;
}

void Point::moveDown()
{
	y = y + 1;
	if (y > MAX_FRAME_FOR_Y)
		y = 0;
}

void Point::moveLeft()
{
	x = x - 1;
	if (x < 0)
		x = MAX_FRAME_FOR_X;
}

void Point::moveRight()
{
	x = x + 1;
	if (x > MAX_FRAME_FOR_X)
		x = 0;
}

void Point::maker(char c)
{
	goXY(x, y);
	std::cout << c;
}

void Point::remove()
{
	goXY(x, y);
	std::cout << " ";
}

void Point::copyPos(Point* entity)
{
	entity->x = x;
	entity->y = y;
}

int Point::isEql(Point* entity)
{
	if (entity->x == x && entity->y == y)
		return 1;
	else
		return 0;
}
