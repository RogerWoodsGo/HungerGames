#include "ComputerPlayer.h"
#include "Board.h"
#include "general.h"

void ComputerPlayer::changeDirection()
{
	setDirection((Direction)(rand()%DIRECTION_OPTION+1));
}

void ComputerPlayer::tryToMove(int playCounter)
{
	char nextPlace;
	Point nextPoint;
	if(playCounter%PLAYER_ROUND_MOVE==0)
	{
		if(rand()%CHANCE_TO_CHANGE_DIRECTION==0)
		{
			changeDirection();
		}
		location->getNextMove(direct,nextPoint);
		nextPlace=location->getBoard()->getContent(nextPoint);
		if(nextPlace==WALL)
		{
			changeDirection();
		}
		else
		{
			move();
		}
	}
}

void ComputerPlayer::tryToShoot(ArrowList& aList,int playCounter)
{
	if(playCounter-lastShootingRound>=PLAYER_ROUND_MOVE*4||lastShootingRound==0)//Computer players can shoot an arrow every 4th move so its every 8th arrow move because arrows are twice as fast as the player
	{
		setShootingOption(ArrowType((rand()%3)+1));
		if(shoot(aList))
		{
			lastShootingRound=playCounter;
		}
	}
}