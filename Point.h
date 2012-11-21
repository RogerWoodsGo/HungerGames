#ifndef _POINT_H_
#define _POINT_H_

#include "general.h"
class Board;// Forward Decleration

class Point
{
	int x,y;
	Point(const Point&);
public:
	Point(){}
	Point(int x1,int y1):x(x1),y(y1){}
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
	char getNextMove(Board& b,Direction direct);
};

#endif