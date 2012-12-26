#ifndef _REGULARARROW_H_
#define _REGULARARROW_H_

#include "Arrow.h"
#include "general.h"

class RegularArrow: public Arrow
{
	RegularArrow(const RegularArrow&);
public:
	RegularArrow(int x,int y,Direction arrowDirect,char symbol):Arrow(x,y,arrowDirect,symbol){}
	virtual void move();
	~RegularArrow(){}
};

#endif