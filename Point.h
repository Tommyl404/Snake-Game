#pragma once
class Point
{
private:
	int x;
	int y;

public:

	Point(); //Ctor.
	Point(int xVal, int yVal); //Parameterized Ctor.

	void SetPoint(int xVal, int yVal); //Set func for Point.

	//Get func's
	int getX();
	int getY();

	//Movement func's for point.
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	
	//func to draw the char and remove the char

	void maker(char c = '0');
	void remove();
	
	//func to copy the position.
	void copyPos(Point* entity);
	
	//func to check if the to entitys are equal.
	int isEql(Point* entity);
};

