#include "HumanPlayer.h"
#include "Board.h"
#include "general.h"

void HumanPlayer::tryToMove(int playCounter)
{
	char nextPlace;
	Point nextPoint;
	if((playCounter%PLAYER_ROUND_MOVE==0)&&(direct!=Center))
	{
		location->getNextMove(direct,nextPoint);
		nextPlace=location->getBoard()->getContent(nextPoint);
		if(nextPlace!=WALL)
		{
			move();
		}
	}
}

void HumanPlayer::tryToShoot(ArrowList& aList,int playCounter)
{
	shoot(aList);
}