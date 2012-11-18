#ifndef _ARROWLIST_H
#define _ARROWLIST_H

#include "ArrowItem.h"

class ArrowList
{
	ArrowItem *head, *tail;
	ArrowList(const ArrowList&);
public:
	ArrowList():head(new ArrowItem),tail(new ArrowItem)
	{
		head->setNext(tail);
		tail->setNext(NULL);
	}
	~ArrowList()
	{
		delete head;
	}
	void Add(const Arrow& arrow);
	void Remove(const Arrow& arrow);
	//void Print();
};

#endif