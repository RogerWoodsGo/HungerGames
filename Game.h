#ifndef _GAME_H_
#define _GAME_H_

//#include "Board.h"
#include "PlayerList.h"

class Game
{
	Game(const Game&);
public:
	Game(){};
	void play(char* fileName);
	void movePlayers(PlayerList& pList);
	void throwGifts();
};

#endif