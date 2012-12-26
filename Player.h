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
	int numOfRegularArrows;
	int numOfPassingArrows;
	int numOfBombingArrows;
	int score;
	int arrowTypeToShoot;
	char symbol;	
	Player(const Player&);
public:
	Player(int x,int y,char ch):location(new Point(x,y)),
		numOfRegularArrows(2),numOfPassingArrows(1),numOfBombingArrows(1),score(1000),symbol(ch),arrowTypeToShoot(0){}
	void drawPlayer(){(*location).draw(symbol);}
	Point* getLocation(){return location;}
	Direction getDirect(){return direct;}
	void setDirection(Direction d){direct=d;}
	int getArrows(){return numOfRegularArrows+numOfPassingArrows+numOfBombingArrows;}
	void getArrows(int& reg,int& pass,int& bomb){reg=numOfRegularArrows;pass=numOfPassingArrows;bomb=numOfBombingArrows;}
	void decreaseArrows(int reg,int pass,int bomb){numOfBombingArrows-=reg;numOfPassingArrows-=pass;numOfRegularArrows-=bomb;}
	void raiseArrows(){numOfRegularArrows++;numOfPassingArrows++;numOfBombingArrows++;}
	int getScore(){return score;}
	void setScore(int num){score=num;}
	char getSymbol(){return symbol;}
	void move();
	void shoot(ArrowList& aList);
	void setShootingOption(int arrowType);
	virtual void tryToMove()=0;
	virtual ~Player(){delete location;};
};

#endif