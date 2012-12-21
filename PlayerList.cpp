#include "PlayerList.h"
#include "Board.h"

void PlayerList::Add(int x,int y,char ch)
{
	PlayerItem* newPlayer;
	newPlayer=new PlayerItem(x,y,ch,head);
	head=newPlayer;
}

void PlayerList::Remove(Player& player)
{
	PlayerItem* curr=head,*saver;
	while(curr->getPlayer()!=&player)
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
	curr->getPlayer()->getLocation()->getBoard()->setContent(*(curr->getPlayer()->getLocation()),' ');
	curr->getPlayer()->getLocation()->draw(' ');
	delete curr;
}

void PlayerList::Print()
{
	PlayerItem* curr=head;
	while(curr!=0)
	{
		curr->getPlayer()->drawPlayer();
		curr=curr->getNext();
	}
}

PlayerList::~PlayerList()
{
	PlayerItem* curr=head,*saver;
	while(curr!=0)
	{
		saver=curr->getNext();
		delete curr;
		curr=saver;
	}
}