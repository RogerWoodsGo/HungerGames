#ifndef _POINT_H_
#define _POINT_H_

#include "general.h"
class Board;// Forward Decleration
class Player;// Forward Decleration
class Arrow;// Forward Decleration

class Point
{
	int x,y;
	const Player* pPlayer;
	const Arrow* pArrow;
	Board* b;
	Point(const Point&);
public:
	Point(){}
	Point(int x1,int y1):pPlayer(0),pArrow(0),x(x1),y(y1){}
	void setArrow(const Arrow* arrow){pArrow=arrow;}
	void setPlayer(const Player* player){pPlayer=player;}
	void setBoard(Board* brd){b=brd;}
	Board* getBoard(){return b;}
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
	void getNextMove(Direction direct,Point& p);
	void setNextMove(Point& p);
	void movePoint(Point& p,char ch);
};

#endif