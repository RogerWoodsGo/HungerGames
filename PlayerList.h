#ifndef _PLAYERLIST_H
#define _PLAYERLIST_H

#include "PlayerItem.h"

class PlayerList
{
	PlayerItem* head;
	PlayerList(const PlayerList&);
public:
	PlayerList():head(0){}
	void Add(int x,int y,char ch);
	void Remove(Player& player);
	PlayerItem* getHead(){return head;}
	void Print();
	~PlayerList();
};

#endif