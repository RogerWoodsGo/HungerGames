#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Point.h"

class Player
{
	Point* location;
	//Direction;
	int numOfArrowes;
	int score;
	char ch;
	Player(const Player&);
public:
	Player(int x,int y,char symbol):location(new Point(x,y)),numOfArrowes(4),score(1000),ch(symbol){}
	const Point* getLocation(){return location;}
	void drawPlayer(){(*location).draw(ch);}
	~Player(){delete location;}
};

#endif