#ifndef _PLAYERLIST_H
#define _PLAYERLIST_H

#include "PlayerItem.h"

class PlayerList
{
	PlayerItem* head;
	PlayerList(const PlayerList&);
public:
	PlayerList():head(0){}
	void add(int x,int y,char ch);
	void remove(Player& player);
	PlayerItem* getHead()const{return head;}
	void print()const;
	void setContent()const;
	~PlayerList();
};

#endif