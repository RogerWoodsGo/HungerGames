#ifndef _PLAYERITEM_H_
#define _PLAYERITEM_H_

#include "Player.h"
#include "general.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "FilePlayer.h"

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
		case Human_Player:
			pPlayer=new HumanPlayer(x,y,ch);
			break;
		case Computer_Player:
			pPlayer=new ComputerPlayer(x,y,ch);
			break;
		case File_Player:
			pPlayer=new FilePlayer(x,y,ch);
			break;
		}
	}
	PlayerItem* getNext()const{return next;}
	Player* getPlayer()const{return pPlayer;}
	void setNext(PlayerItem* nextPlayer){next=nextPlayer;}
	~PlayerItem(){delete pPlayer;}
};

#endif