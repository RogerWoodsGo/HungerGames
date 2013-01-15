#ifndef _ARROWLIST_H
#define _ARROWLIST_H

#include "ArrowItem.h"

class ArrowList
{
	ArrowItem* head;
	ArrowList(const ArrowList&);
public:
	ArrowList():head(NULL){}
	void add(int x,int y,Direction direct,char ch);
	void remove(Arrow& arrow);
	ArrowItem* getHead()const{return head;}
	void print()const;
	~ArrowList();
};

#endif