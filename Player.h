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
	void setDirect(Direction newDirect){direct=newDirect;}
	Point* getPlace(){return location;}
	Direction getDirect(){return direct;}
	Direction randomDirection();
	~Player(){delete location;}
};

#endif