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
	Board():numOfPlayersOnBoard(0),scoreBoardPlace(0,0){}
	void readFile(char* fileName,PlayerList& pList);
	void setText(char** textToSet){text=textToSet;}
	char** getText(){return text;}
	void printText(PlayerList& pList);
	char getContent(Point& p);
	void setContent(Point& p,char ch);
	bool checkBoard(PlayerList& pList);
	bool randomLocation(Point& p);
	void throwGifts();
<<<<<<< HEAD
	void chen();
=======
	void Vladik();
>>>>>>> d3ccc80f1f0d9c524c7e5bafe7e0cd1d04763599
	~Board();
};

#endif