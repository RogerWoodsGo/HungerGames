#ifndef _ARROW_H_
#define _ARROW_H_

#include "Point.h"
#include "general.h"

class Arrow
{
protected:
	Point* location;
	Direction direct;
	char giftSteppedOn;
	char symbol;
	bool iAmAlive;
	Arrow(const Arrow&);
public:
	Arrow(int x,int y,Direction arrowDirect,char ch):
	  location(new Point(x,y)),direct(arrowDirect),symbol(ch),iAmAlive(true),giftSteppedOn(' '){}
	void drawArrow()const{(*location).draw(symbol);}
	void setGiftSteppedOn(char ch){giftSteppedOn=ch;}
	char getGiftSteppedOn()const{return giftSteppedOn;}
	void setKillArrow(){iAmAlive=false;}
	bool getIAmAlive()const{return iAmAlive;}
	Point* getLocation()const{return location;}
	virtual void move()=0;
	virtual ~Arrow(){delete location;}
};

#endif