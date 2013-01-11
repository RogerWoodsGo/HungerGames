#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Point.h"
#include "general.h"
#include "ArrowList.h"

class Player
{
protected:
	Point* location;
	Direction direct;
	int numOfBombingArrows;
	int numOfPassingArrows;
	int numOfRegularArrows;
	int score;
	ArrowType arrowToShoot;
	char symbol;
	int lastShootingRound;
	Player(const Player&);
public:
	Player(int x,int y,char ch):location(new Point(x,y)),
		numOfRegularArrows(2),numOfPassingArrows(1),numOfBombingArrows(1),score(10000),symbol(ch),arrowToShoot(None),lastShootingRound(0){}
	void drawPlayer()const{(*location).draw(symbol);}
	Point* getLocation()const{return location;}
	Direction getDirect()const{return direct;}
	void setDirection(Direction d){direct=d;}
	void getArrows(int& bomb,int& pass,int& reg)const{bomb=numOfBombingArrows;pass=numOfPassingArrows;reg=numOfRegularArrows;}
	void decreaseArrows(int bomb,int pass,int reg){numOfBombingArrows-=bomb;numOfPassingArrows-=pass;numOfRegularArrows-=reg;}
	void raiseArrows(){numOfBombingArrows++;numOfPassingArrows++;numOfRegularArrows++;}
	int getScore()const{return score;}
	void setScore(int num){score=num;}
	char getSymbol()const{return symbol;}
	void move();
	bool shoot(ArrowList& aList);
	void setShootingOption(ArrowType arrow);
	virtual void tryToMove()=0;
	virtual void tryToShoot(ArrowList& aList,int playCounter)=0;
	virtual ~Player(){delete location;}
};

#endif