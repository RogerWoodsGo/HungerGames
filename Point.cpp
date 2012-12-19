#include "Point.h"
#include "Board.h"
#include <windows.h>
#include <process.h>

void Point::draw(char c)
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
	if((ch==REGULAR_ARROW)||(ch==PASSING_ARROW)||(ch==BOMBING_ARROW))
	{
		p.getPlace(x,y);//Get the new place for arrow
		setPlace(x,y);//Set the new place for arrow
		draw(ch);//Draw arrow on screen
		getBoard()->setContent(p,ch);//Write the arrow to the text	
	}
	else
	{
		draw(' ');//Remove player from screen
		getBoard()->setContent(currentPoint,' ');//Remove player from text
		p.getPlace(x,y);//Get the new place for player
		setPlace(x,y);//Set the new place for player
		draw(ch);//Draw player on screen
		getBoard()->setContent(p,PLAYER);//Write the player to the text
	}
}