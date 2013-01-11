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
	char** files;
	int numOfFiles;
	Game(const Game&);
public:
	Game(int argc):playCounter(0),numOfFiles(argc-1),files(new char*[NUM_OF_FILE_TYPES]){}
	void run(char** argv);
	bool organizeFiles(char** argv);
	bool insertToFiles(const FileType type,char* str);
	void play();
	bool isThereAWinner();
	void playPlayers();
	void moveArrows();
	bool checkPressedKeys();
	~Game(){delete []files;}
};

#endif