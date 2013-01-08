#include "HumanPlayer.h"
#include "Board.h"
#include "general.h"

void HumanPlayer::tryToMove()
{
	char nextPlace;
	Point nextPoint;
	if(direct!=Center)
	{
		location->getNextMove(direct,nextPoint);
		nextPlace=location->getBoard()->getContent(nextPoint);
		if(nextPlace!=WALL)
			move();
	}
}

void HumanPlayer::tryToShoot(ArrowList& aList,int playCounter)
{
	shoot(aList);
}