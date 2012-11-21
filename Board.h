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
	void readFile(char* fileName,char** text,int& numOfPlayersOnBoard,Point& scoreBoardPlace,PlayerList& pList);
	void setText(char** textToSet){text=textToSet;}
	char** getText(){return text;}
	void printText(char** text,PlayerList& pList);
	//char getContent(int x, int y);
};

#endif