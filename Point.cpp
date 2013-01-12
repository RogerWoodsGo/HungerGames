#include "Point.h"
#include "Board.h"
#include <windows.h>
#include <process.h>

void Point::draw(const char c)const
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X=y;
	dwCursorPosition.Y=x;
	hConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
	cout << c;
}

void Point::getNextMove(const Direction direct,Point& p)const
{
	int nextX=x,nextY=y;
	switch (direct)
	{
	case Up:	nextX=(x-1+HEIGHT)%HEIGHT;	break;
	case Left:	nextY=(y-1+WIDTH)%WIDTH;	break;
	case Down:	nextX=(x+1+HEIGHT)%HEIGHT;	break;
	case Right:	nextY=(y+1+WIDTH)%WIDTH;	break;
	}
	p.setPlace(nextX,nextY);
}