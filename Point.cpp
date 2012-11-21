#include "Point.h"
#include <windows.h>
#include <process.h>

void Point::draw(char c)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
	cout << c;
}

char Point::getNextMove(char** text,Direction direct)
{
	int nextX=x,nextY=y;
	switch (direct)
		{
		case Up:	nextY=(y-1+HEIGHT)%HEIGHT;	break;
		case Right:	nextX=(x+1+WIDTH)%WIDTH;	break;
		case Down:	nextY=(y+1+HEIGHT)%HEIGHT;	break;
		case Left:	nextX=(x-1+WIDTH)%WIDTH;	break;
		}
	return text[nextY][nextX];
}