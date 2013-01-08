#ifndef _GAME_H_
#define _GAME_H_

#include "Board.h"
#include "PlayerList.h"
#include "ArrowList.h"

class Game
{
	Board b;
	PlayerList pList;
	ArrowList aList;
	int playCounter;
	Game(const Game&);
public:
	Game():playCounter(0){};
	void run(char* fileName);
	void play(char* fileName);
	bool isThereAWinner();
	void playPlayers();
	void moveArrows();
	bool checkPressedKeys();
};

#endif