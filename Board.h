#ifndef _BOARD_H_
#define _BOARD_H_

#include "PlayerList.h"
#include "general.h"
#include "Point.h"

class Board
{
	char** text;
	int numOfPlayersOnBoard;
	Point scoreBoardPlace;
	Board(const Board&);
public:
	Board():text(0),numOfPlayersOnBoard(0),scoreBoardPlace(0,0){}
	void readFile(char* fileName,PlayerList& pList);
	void setText(char** textToSet){text=textToSet;}
	char** getText(){return text;}
	void printText(PlayerList& pList);
	char getContent(int x, int y);
	~Board();
};

#endif