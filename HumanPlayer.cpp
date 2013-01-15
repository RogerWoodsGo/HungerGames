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
	if(playCounter-lastShootingRound>=PLAYER_ROUND_MOVE*(NUM_OF_ROUNDS_TO_WAIT+1)||lastShootingRound==0)//Players can shoot an arrow every 4th move so its every 8th arrow move because arrows are twice as fast as the player
	{
		if(shoot(aList))
		{
			lastShootingRound=playCounter;
		}
	}
}