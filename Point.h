#ifndef _POINT_H_
#define _POINT_H_

#include <windows.h>
#include <process.h>
#include "general.h"

class Point
{
	int x,y;
	Point(const Point&);
public:
	Point(int x1,int y1):x(x1),y(y1){}
	Point(){}
	void setPlace(int x1,int y1)
	{
		x=x1;
		y=y1;
	}
	void getPlace(int& x1,int& y1)
	{
		x1=x;
		y1=y;
	}
	void draw(char c)
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
};

#endif