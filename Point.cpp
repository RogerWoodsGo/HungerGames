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

void Point::getNextMove(Direction direct,Point& p)
{
	int nextX=x,nextY=y;
	switch (direct)
	{
	case Up:	nextX=(x-1+HEIGHT)%HEIGHT;	break;
	case Right:	nextY=(y-1+WIDTH)%WIDTH;	break;
	case Down:	nextX=(x+1+HEIGHT)%HEIGHT;	break;
	case Left:	nextY=(y+1+WIDTH)%WIDTH;	break;
	}
	p.setPlace(nextX,nextY);
}

void Point::movePoint(Point& p,char ch)
{
	int x,y;
	Point currentPoint;
	getPlace(x,y);
	currentPoint.setPlace(x,y);
	draw(' ');//Remove player from screen
	getBoard()->setContent(currentPoint,' ');//Remove player from text
	p.getPlace(x,y);//Get the new place for player
	setPlace(x,y);//Set the new place for player
	draw(ch);//Draw player on screen
	getBoard()->setContent(p,'P');//

}