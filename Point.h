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
	Board* getBoard()const{return b;}
	void setPlace(int x1,int y1){x=x1;y=y1;}
	void getPlace(int& x1,int& y1)const{x1=x;y1=y;}
	void setNextMove(Point& p);
	void getNextMove(const Direction direct,Point& p)const;
	void draw(const char c)const;
};

#endif