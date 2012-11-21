#include "Point.h"
#include "Board.h"
//#include "Arrow.h"
#include "Player.h"
#include <windows.h>
#include <process.h>

void Point::draw(char c)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = y;
	dwCursorPosition.Y = x;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
	cout << c;
}

char Point::getNextMove(Board& b,Direction direct)
{
	int nextX=x,nextY=y;
	switch (direct)
		{
		case Up:	nextY=(y-1+HEIGHT)%HEIGHT;	break;
		case Right:	nextX=(x+1+WIDTH)%WIDTH;	break;
		case Down:	nextY=(y+1+HEIGHT)%HEIGHT;	break;
		case Left:	nextX=(x-1+WIDTH)%WIDTH;	break;
		}
	return b.getContent(nextX,nextY);
}