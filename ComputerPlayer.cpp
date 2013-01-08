#include "ComputerPlayer.h"
#include "Board.h"
#include "general.h"

void ComputerPlayer::changeDirection()
{
	setDirection((Direction)(rand()%DIRECTION_OPTION+1));
}

void ComputerPlayer::tryToMove()
{
	char nextPlace;
	Point nextPoint;
	if(rand()%CHANCE_TO_CHANGE_DIRECTION==0)
		changeDirection();
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
