#ifndef _POINT_H_
#define _POINT_H_

#include "general.h"
class Board;// Forward Decleration

class Point
{
	int x,y;
	Board* b;
	Point(const Point&);
public:
	Point(){}
	Point(int x1,int y1):x(x1),y(y1){}
	void setBoard(Board* brd){b=brd;}
	Board* getBoard(){return b;}
	void setPlace(int x1,int y1){x=x1;y=y1;}
	void getPlace(int& x1,int& y1){x1=x;y1=y;}
	void setNextMove(Point& p);
	void getNextMove(Direction direct,Point& p);
	void draw(char c);
};

#endif