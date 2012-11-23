#ifndef _PLAYERITEM_H_
#define _PLAYERITEM_H_

#include "Player.h"
class PlayerList;// Forward Decleration

class PlayerItem
{
	Player* pPlayer;
	PlayerItem* next;
	const PlayerList* pList;
	PlayerItem(const PlayerItem&);
public:
	PlayerItem(const PlayerList* lst,int x,int y,char ch,PlayerItem* head):pList(lst),pPlayer(new Player(x,y,ch)),next(head){pPlayer->setItem(this);}
	PlayerItem():pPlayer(0),next(0){}
	~PlayerItem()
	{
		delete pPlayer;
		delete next;
	}
	PlayerItem* getNext(){return next;}
	Player* getPlayer(){return pPlayer;}
	//PlayerList* getPlayerList(){return pList;}
	void setNext(PlayerItem* nextPlayer){next = nextPlayer;}
};

#endif