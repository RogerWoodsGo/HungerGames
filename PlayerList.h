#ifndef _PLAYERLIST_H
#define _PLAYERLIST_H

#include "PlayerItem.h"

class PlayerList
{
	PlayerItem* head;
	PlayerList(const PlayerList&);
public:
	PlayerList():head(NULL){}
	void add(int x,int y,char ch,PlayerType type);
	void remove(Player& player);
	PlayerItem* getHead()const{return head;}
	void print()const;
	void setContent()const;
	~PlayerList();
};

#endif