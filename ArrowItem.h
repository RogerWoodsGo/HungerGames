#ifndef _ARROWITEM_H_
#define _ARROWITEM_H_

#include "Arrow.h"
#include "RegularArrow.h"
#include "PassingArrow.h"
#include "BombingArrow.h"

class ArrowItem
{
	Arrow* pArrow;
	ArrowItem* next;
	ArrowItem(const ArrowItem&);
public:
	ArrowItem(int x,int y,Direction direct,ArrowItem* head,char ch):next(head)
	{
		if(ch==REGULAR_ARROW)
		{
			pArrow=new RegularArrow(x,y,direct,ch);
		}
		else if(ch==PASSING_ARROW)
		{
			pArrow=new PassingArrow(x,y,direct,ch);
		}
		else if(ch==BOMBING_ARROW)
		{
			pArrow=new BombingArrow(x,y,direct,ch);
		}
	}
	ArrowItem():pArrow(0),next(0){}
	ArrowItem* getNext()const{return next;}
	Arrow* getArrow()const{return pArrow;}
	void setNext(ArrowItem* nextArrow){next=nextArrow;}
	~ArrowItem(){delete pArrow;}
};

#endif