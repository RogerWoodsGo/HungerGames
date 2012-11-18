#ifndef _BOARD_H_
#define _BOARD_H_

#include "PlayerList.h"
#include "general.h"
#include "Point.h"


class Board
{
	char** text;
	Board(const Board&);
public:
	Board(){};
	void readFile(char* fileName,char text[HEIGHT][WIDTH+1],int& numOfPlayersOnBoard,Point& scoreBoardPlace,PlayerList& pList);
	void printText(char text[HEIGHT][WIDTH+1],PlayerList& pList);
};

#endif