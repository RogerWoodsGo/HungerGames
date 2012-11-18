#ifndef _PLAYERITEM_H_
#define _PLAYERITEM_H_

#include "Player.h"

class PlayerItem
{
	Player* pPlayer;
	PlayerItem* next;
	PlayerItem(const PlayerItem&);
public:
	PlayerItem(int x,int y,char ch,PlayerItem* head):pPlayer(new Player(x,y,ch)),next(head){}
	PlayerItem():pPlayer(0),next(0){}
	~PlayerItem()
	{
		delete pPlayer;
		delete next;
	}
	PlayerItem* getNext(){return next;}
	Player* getPlayer(){return pPlayer;}
	void setNext(PlayerItem* nextPlayer){next = nextPlayer;}
};

#endif