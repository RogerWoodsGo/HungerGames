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

bool ComputerPlayer::timeToShoot()
{
	if(shootTime%(PLAYER_ROUND_MOVE*4)==0) //player can shoot an arrow every 4th move so its every 8th arrow move because arrows are twice as fast as the player
	{
		return true;
	}
	else
	{
		return false;
	}
	shootTime++;
}