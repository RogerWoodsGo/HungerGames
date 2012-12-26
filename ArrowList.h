#ifndef _ARROWLIST_H
#define _ARROWLIST_H

#include "ArrowItem.h"

class ArrowList
{
	ArrowItem* head;
	ArrowList(const ArrowList&);
public:
	ArrowList():head(0){}
	void add(int x,int y,Direction direct,char ch);
	void remove(Arrow& arrow);
	ArrowItem* getHead(){return head;}
	void print();
	~ArrowList();
};

#endif