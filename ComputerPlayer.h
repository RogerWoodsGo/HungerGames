#ifndef _COMPUTERPLAYER_H_
#define _COMPUTERPLAYER_H_

#include "Player.h"

class ComputerPlayer: public Player
{
	ComputerPlayer(const ComputerPlayer&);
public:
	ComputerPlayer(int x,int y,char ch):Player(x,y,ch){changeDirection();};
	void changeDirection();
	virtual void tryToMove();
	virtual bool timeToShoot();
	~ComputerPlayer(){}
};

#endif