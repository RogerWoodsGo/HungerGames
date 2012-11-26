#include "ArrowList.h"
#include "Board.h"

void ArrowList::Add(int x,int y,Direction direct)
{
	ArrowItem* newArrow;
	newArrow=new ArrowItem(x,y,direct,head);
	head=newArrow;
}

void ArrowList::Remove(Arrow& arrow)
{
	ArrowItem* curr=head,*saver;
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
	delete curr;
}

void ArrowList::Print()
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