#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <dos.h>
#include "Point.h"
#include "Player.h"
#pragma warning(disable : 4996)

#define MAX_SNAKE 100
#define MAX_FRAME_FOR_X 119
#define MAX_FRAME_FOR_Y 29

using namespace std; //make's my life simple

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorCoord;


void setCursor(bool canSee, DWORD size) 
{
	if (size == 0)
		size = 20; //def for size.
	CONSOLE_CURSOR_INFO cCell;
	cCell.bVisible = canSee; //canSee = 0 unseen. canSee = 1 seen.
	cCell.dwSize = size; // 1-40 -> makes changes to the cursor appearance
}

int main() {
	//random no generation
	setCursor(0, 0);
	srand((unsigned)time(NULL));

	// Testing snake 
	Player player;
	char op = 'l';
	do {
		if (kbhit()) {
			op = getch();
		}
		switch (op) {
		case 'w':
		case 'W':
			player.playerUp();
			break;

		case 's':
		case 'S':
			player.playerDown();
			break;

		case 'a':
		case 'A':
			player.playerLeft();
			break;

		case 'd':
		case 'D':
			player.playerRight();
			break;
		}
		player.playerMove();
	} while (op != 'e');

	return 0;
}