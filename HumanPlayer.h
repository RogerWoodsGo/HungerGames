#ifndef _HUMANPLAYER_H_
#define _HUMANPLAYER_H_

#include "Player.h"

class HumanPlayer: public Player
{
public:
	HumanPlayer(int x,int y,char ch):Player(x,y,ch){setDirection(Center);};
	virtual void tryToMove();
	~HumanPlayer(){}
};

#endif