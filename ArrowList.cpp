#include "ArrowList.h"

void ArrowList::Add(const Arrow& arrow)
{
	ArrowItem* newArrow = new ArrowItem(arrow);

	tail->setNext(newArrow);
	tail=newArrow;
}

void ArrowList::Remove(const Arrow& arrow)
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
	else if(curr==tail)
	{
		tail=saver;
	}
	else
	{
		saver=curr->getNext();
	}
	delete curr;
}

/*
void List::Print()
{
	for(Item* curr = head->getNext();
		curr != tail;
		curr = curr->getNext())
	{
			curr->getData()->Print();
	}
}
*/