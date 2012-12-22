#include "ComputerPlayer.h"
#include "PlayerItem.h"
#include "Board.h"
#include "general.h"

void ComputerPlayer::setDirection()
{
	direct=(Direction)(rand()%DIRECTION_OPTION+1);
}

void ComputerPlayer::move()
{
	int score=getScore();
	char nextPlace;
	Point nextPoint;
	int x,y;
	if(rand()%CHANCE_TO_CHANGE_DIRECTION==0)
		setDirection();
	location->getNextMove(direct,nextPoint);
	nextPlace=location->getBoard()->getContent(nextPoint);
	if(nextPlace==WALL)
	{
		setDirection();
	}
	else
	{
		location->draw(' ');//Remove player from screen
		location->getBoard()->setContent(*location,' ');//Remove player from text
		nextPoint.getPlace(x,y);//Get the new place for player
		location->setPlace(x,y);//Set the new place for player
		switch (nextPlace)
		{
		case 'P':
			location->getBoard()->playerFight(*location);
			break;
		case ARROW:
			location->getBoard()->arrowHitsPlayer(*location);
			break;
		case FOOD_GIFT:
			setScore(score+FOOD_BONUS);
			break;
		case ARROW_GIFT:
			raiseArrows();
			break;
		case BOMB_GIFT:
			setScore(score+BOMB_BONUS);
			break;
		}
		location->draw(ch);//Draw player on screen
		location->getBoard()->setContent(nextPoint,PLAYER);//Write the player to the text	
	}
}