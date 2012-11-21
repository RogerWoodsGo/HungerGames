#ifndef _POINT_H_
#define _POINT_H_

//#include "Board.h"
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
	void draw(char c);
	char getNextMove(char** text,Direction direct);
};

#endif