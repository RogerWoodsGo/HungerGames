#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Point.h"
#include "general.h"

class Player
{
	Point* location;
	Direction direct;
	int numOfArrows;
	int score;
	char ch;	
	Player(const Player&);
public:
	Player(int x,int y,char symbol):location(new Point(x,y)),numOfArrows(4),score(1000),ch(symbol),direct(randomDirection()){}
	void drawPlayer(){(*location).draw(ch);}
	Point* getLocation(){return location;}
	Direction getDirect(){return direct;}
	int getArrows(){return numOfArrows;}
	void setArrows(int num){numOfArrows=num;}
	int getScore(){return score;}
	void setScore(int num){score=num;}
	char getChar(){return ch;}
	void setDirection();
	Direction randomDirection();
	void move();
	~Player(){delete location;}
};

#endif