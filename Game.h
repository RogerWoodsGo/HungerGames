#ifndef _GAME_H_
#define _GAME_H_

#include "PlayerList.h"
//#include "ArrowList.h"

class Game
{
	Game(const Game&);
public:
	Game(){};
	void play(char* fileName);
	void movePlayers(PlayerList& pList);
	//void moveArrows(ArrowList& pList);
};

#endif