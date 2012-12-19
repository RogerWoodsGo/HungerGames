#ifndef _BOARD_H_
#define _BOARD_H_

#include "PlayerList.h"
#include "ArrowList.h"
#include "Point.h"

class Board
{
	char** text;
	int numOfComputerPlayersOnBoard;
	int numOfHumanPlayersOnBoard;
	Point scoreBoardPlace;
	PlayerList* pList;
	ArrowList* aList;
	Board(const Board&);
public:
	Board();
	void readFile(char* fileName);
	//char** getText(){return text;}
	void setPList(PlayerList& lst){pList=&lst;}
	void setAList(ArrowList& lst){aList=&lst;}
	void printText();
	char getContent(Point& p);
	void setContent(Point& p,char ch);
	bool checkBoard();
	bool randomLocation(Point& p);
	void throwGifts();
	bool isPointInScoreBoard(Point& p);
	bool isPointNearAPlayer(Point& p);
	void playerFight(Point& p);
	void arrowHitsPlayer(Point& p);
	void printScoreBoard();
	~Board();
};

#endif