#include "ArrowList.h"
#include "Board.h"

void ArrowList::add(int x,int y,Direction direct,char ch)
{
	ArrowItem* newArrow;
	newArrow=new ArrowItem(x,y,direct,head,ch);
	head=newArrow;
}

void ArrowList::remove(Arrow& arrow)
{
	ArrowItem* curr=head,*saver;
	char giftSteppedOn;
	while(curr->getArrow()!=&arrow)
	{
		if(curr==head)
		{
			saver=head;
		}
		else
		{
			saver=saver->getNext();
		}
		curr=curr->getNext();
	}
	if(curr==head)
	{
		head=curr->getNext();
	}
	else
	{
		saver->setNext(curr->getNext());
	}
	giftSteppedOn=curr->getArrow()->getGiftSteppedOn();
	curr->getArrow()->getLocation()->getBoard()->setContent(*(curr->getArrow()->getLocation()),giftSteppedOn);
	delete curr;
}

void ArrowList::print()
{
	ArrowItem* curr=head;
	while(curr!=0)
	{
		curr->getArrow()->drawArrow();
		curr=curr->getNext();
	}
}

ArrowList::~ArrowList()
{
	ArrowItem* curr=head,*saver;
	while(curr!=0)
	{
		saver=curr->getNext();
		delete curr;
		curr=saver;
	}
}