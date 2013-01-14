#ifndef _BOARD_H_
#define _BOARD_H_

#include "PlayerList.h"
#include "ArrowList.h"
#include "Player.h"
#include "Point.h"

class Board
{
	char** text;
	int numOfComputerPlayersOnBoard;
	int numOfHumanPlayersOnBoard;
	int numOfFilePlayersOnBoard;
	Point scoreBoardPlace;
	PlayerList* pList;
	ArrowList* aList;
	Player* human;
	map<int,vector<char>*>* giftMap;
	Board(const Board&);
public:
	Board();
	void readFile(char** files);
	void mapFile(map<int,vector<char>*>* eventMap,const char* file);
	map<int,vector<char>*>* getGiftMap(){return giftMap;}
	void setPList(PlayerList& lst){pList=&lst;}
	void setAList(ArrowList& lst){aList=&lst;}
	void printText()const;
	char getContent(const Point& p)const;
	void setContent(const Point& p,char ch)const;
	bool checkBoard();
	bool randomLocation(Point& p)const;
	void throwGifts(int playCounter);
	void throwAutoGifts()const;
	void throwMapGifts(int playCounter);
	void tryToThrowAGift(const char ch)const;
	bool isPointInScoreBoard(const Point& p)const;
	bool isPointNearAPlayer(const Point& p)const;
	void playerFight(const Point& p)const;
	void arrowHitsPlayer(const Point& p)const;
	void printScoreBoard(int playCounter)const;
	void setHumanPlayer(Player* p){human=p;}
	int getNumOfPlayerOnBoard(){return numOfComputerPlayersOnBoard+numOfHumanPlayersOnBoard+numOfFilePlayersOnBoard;}
	Player* getHumanPlayer()const{return human;}
	void freeMap(map<int,vector<char>*>* eventMap);
	~Board();
};

#endif