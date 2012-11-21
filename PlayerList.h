#ifndef _PLAYERLIST_H
#define _PLAYERLIST_H

#include "PlayerItem.h"
class Board;// Forward Decleration

class PlayerList
{
	Board* b;
	PlayerItem* head;
	char numOfPlayers;
	PlayerList(const PlayerList&);
public:
	PlayerList(Board& brd):b(&brd),head(0),numOfPlayers(0){}
	void Add(int x,int y);
	void Remove(const Player& player);
	PlayerItem* getHead(){return head;}
	void Print();
	~PlayerList(){delete head;}
};

#endif