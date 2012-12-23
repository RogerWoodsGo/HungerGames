#include "Player.h"
#include "Board.h"

void Player::move()
{
	char nextPlace;
	Point nextPoint;
	int x,y;
	location->getNextMove(direct,nextPoint);
	nextPlace=location->getBoard()->getContent(nextPoint);
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