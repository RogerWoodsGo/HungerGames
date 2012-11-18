#ifndef _DRAW_H
#define _DRAW_H
#include <windows.h>
#include <process.h>
#include "Point.h"
//#include "general.h"

void gotoxy(Point& p)
{
	int x1,y1;
	p.getPlace(x1,y1);
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = x1;
	dwCursorPosition.Y = y1;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

//void draw(Point& p,char c)
void draw(Point& p,char c)
{
	gotoxy(p);
	cout << c;
}

#endif