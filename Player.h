#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Point.h"
#include "general.h"
class PlayerItem;//Forward Decleration

class Player
{
	const PlayerItem* pItem;
	Point* location;
	Direction direct;
	int numOfArrows;
	int score;
	char ch;	
	Player(const Player&);
public:
	Player(int x,int y,char symbol):location(new Point(x,y)),numOfArrows(4),score(1000),ch(symbol),direct(randomDirection()){}
	void setItem(const PlayerItem* item){pItem=item;}
	void drawPlayer(){(*location).draw(ch);}
	//void setDirect(Direction newDirect){direct=newDirect;}
	Point* getPlace(){return location;}
	Direction getDirect(){return direct;}
	int getArrows(){return numOfArrows;}
	void setArrows(int num){numOfArrows=num;}
	int getScore(){return score;}
	void setScore(int num){score=num;}
	char getChar(){return ch;}
	void setDirection();
	Direction randomDirection();
	void move();
	//PlayerItem* getPlayerItem(){return pItem;}
	~Player(){delete location;}
};

#endif