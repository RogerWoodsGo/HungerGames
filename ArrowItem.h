#ifndef _ARROWITEM_H_
#define _ARROWITEM_H_

#include "Arrow.h"

class ArrowItem
{
	const Arrow* pArrow;
	ArrowItem* next;
	ArrowItem(const ArrowItem&);
public:
	ArrowItem(const Arrow& arrow):pArrow(&arrow),next(0){}
	ArrowItem():pArrow(0),next(0){}
	~ArrowItem()
	{
		delete pArrow;
		delete next;
	}
	ArrowItem* getNext(){return next;}
	const Arrow* getArrow(){return pArrow;}
	void setNext(ArrowItem* nextArrow){next = nextArrow;}
	//void setArrow(Arrow* pArrow){this->pArrow = pArrow;}
};

#endif