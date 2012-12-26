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
	Direction lastDirection;
	int lastArrowType;
	Game(const Game&);
public:
	Game():lastDirection(Center),lastArrowType(0){};
	void run(char* fileName);
	void play(char* fileName);
	bool isThereAWinner();
	void movePlayers()const;
	void moveArrows();
	void shootArrows();
	bool checkPressedKeys();
};

#endif