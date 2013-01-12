#ifndef _PLAYERITEM_H_
#define _PLAYERITEM_H_

#include "Player.h"
#include "general.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"

class PlayerItem
{
	Player* pPlayer;
	PlayerItem* next;
	PlayerItem(const PlayerItem&);
public:
	PlayerItem(int x,int y,char ch,PlayerItem* head,PlayerType type):next(head)
	{
		switch(type)
		{
		case HPlayer:
			pPlayer=new HumanPlayer(x,y,ch);
			break;
		case PPlayer:
			pPlayer=new ComputerPlayer(x,y,ch);
			break;
		}
	}
	PlayerItem():pPlayer(0),next(0){}
	PlayerItem* getNext()const{return next;}
	Player* getPlayer()const{return pPlayer;}
	void setNext(PlayerItem* nextPlayer){next=nextPlayer;}
	~PlayerItem(){delete pPlayer;}
};

#endif