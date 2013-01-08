#ifndef _HUMANPLAYER_H_
#define _HUMANPLAYER_H_

#include "Player.h"

class HumanPlayer: public Player
{
	HumanPlayer(const HumanPlayer&);
public:
	HumanPlayer(int x,int y,char ch):Player(x,y,ch){setDirection(Center);};
	virtual void tryToMove();
	virtual void tryToShoot(ArrowList& aList,int playCounter);
	~HumanPlayer(){}
};

#endif