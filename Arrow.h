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
	char ch;
	bool iAmAlive;
	Arrow(const Arrow&);
public:
	Arrow(int x,int y,Direction arrowDirect,char symbol):location(new Point(x,y)),direct(arrowDirect),ch(symbol),iAmAlive(true){}
	void drawArrow(){(*location).draw(ch);}
	void setGiftSteppedOn(char ch){giftSteppedOn=ch;}
	char getGiftSteppedOn(){return giftSteppedOn;}
	void setKillArrow(){iAmAlive=false;}
	bool getIAmAlive(){return iAmAlive;}
	Point* getLocation(){return location;}
	virtual void move()=0;
	virtual ~Arrow(){delete location;}
};

#endif