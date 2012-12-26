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
	PlayerItem* getHead(){return head;}
	void print();
	void setContent();
	~PlayerList();
};

#endif