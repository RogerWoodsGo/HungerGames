#ifndef _PASSINGARROW_H_
#define _PASSINGARROW_H_

#include "Arrow.h"
#include "general.h"

class PassingArrow: public Arrow
{
public:
	PassingArrow(int x,int y,Direction arrowDirect,char symbol):Arrow(x,y,arrowDirect,symbol){}
	virtual void move();
	~PassingArrow(){}
};

#endif