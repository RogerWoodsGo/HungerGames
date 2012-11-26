#ifndef _GAME_H_
#define _GAME_H_

#include "PlayerList.h"
#include "ArrowList.h"

class Game
{
	Game(const Game&);
public:
	Game(){};
	void play(char* fileName);
	bool isThereAWinner(PlayerList& pList);
	void movePlayers(PlayerList& pList);
	void moveArrows(ArrowList& aList);
	void shootArrows(PlayerList& pList,ArrowList& aList);
};

#endif