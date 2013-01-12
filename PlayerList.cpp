#include "PlayerList.h"
#include "Board.h"

void PlayerList::add(int x,int y,char ch,PlayerType type)
{
	PlayerItem* newPlayer;
	newPlayer=new PlayerItem(x,y,ch,head,type);
	head=newPlayer;
}

void PlayerList::remove(Player& player)
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

void PlayerList::print()const
{
	PlayerItem* curr=head;
	while(curr!=0)
	{
		curr->getPlayer()->drawPlayer();
		curr=curr->getNext();
	}
}

void PlayerList::setContent()const
{
	PlayerItem* curr=head;
	Board* b=head->getPlayer()->getLocation()->getBoard();
	while(curr!=0)
	{
		b->setContent(*(curr->getPlayer()->getLocation()),PLAYER);
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