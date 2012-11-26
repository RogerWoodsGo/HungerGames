#ifndef _ARROWITEM_H_
#define _ARROWITEM_H_

#include "Arrow.h"

class ArrowItem
{
	Arrow* pArrow;
	ArrowItem* next;
	ArrowItem(const ArrowItem&);
public:
	ArrowItem(int x,int y,Direction direct,ArrowItem* head):pArrow(new Arrow(x,y,direct)),next(head){}
	ArrowItem():pArrow(0),next(0){}
	ArrowItem* getNext(){return next;}
	Arrow* getArrow(){return pArrow;}
	void setNext(ArrowItem* nextArrow){next=nextArrow;}
	~ArrowItem(){delete pArrow;}
};

#endif