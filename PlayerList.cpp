#include "PlayerList.h"
#include "Board.h"

void PlayerList::Add(int x,int y)
{
	PlayerItem* newPlayer;
	numOfPlayers++;
	newPlayer = new PlayerItem(x,y,numOfPlayers,head);
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
	delete curr;
	numOfPlayers--;
}

void PlayerList::Print()
{
	PlayerItem* curr = head;
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