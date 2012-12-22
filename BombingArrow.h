#ifndef _BOMBINGARROW_H_
#define _BOMBINGARROW_H_

#include "Arrow.h"
#include "general.h"

class BombingArrow: public Arrow
{
public:
	BombingArrow(int x,int y,Direction arrowDirect,char symbol):Arrow(x,y,arrowDirect,symbol){}
	virtual void move();
	~BombingArrow(){}
};

#endif