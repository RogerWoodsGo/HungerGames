#include "PlayerList.h"
#include "Board.h"

void PlayerList::Add(int x,int y)
{
	PlayerItem* newPlayer;
	numOfPlayers++;
	newPlayer = new PlayerItem(this,x,y,numOfPlayers,head);
	head=newPlayer;
}

void PlayerList::Remove(const Player& player)
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