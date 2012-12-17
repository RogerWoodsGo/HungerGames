#include "Player.h"
#include "PlayerItem.h"
#include "Board.h"

Direction Player::randomDirection()
{
	return (Direction)(rand()%DIRECTION_OPTION);
}

void Player::setDirection()
{
	direct=randomDirection();
}

void Player::move()
{
	int score=getScore();
	int arrows=getArrows();
	char nextPlace;
	Point p;
	if(rand()%CHANCE_TO_CHANGE_DIRECTION==0)
		setDirection();
	location->getNextMove(direct,p);
	nextPlace=location->getBoard()->getContent(p);
	switch (nextPlace)
	{
	case WALL:
		setDirection();
		break;
	case 'P':
		location->movePoint(p,ch);
		location->getBoard()->playerFight(*location);
		break;
	case ARROW:
		location->movePoint(p,ch);
		location->getBoard()->arrowHitsPlayer(*location);
		break;
	case FOOD_GIFT:
		location->movePoint(p,ch);
		setScore(score+FOOD_BONUS);
		break;
	case ARROW_GIFT:
		location->movePoint(p,ch);
		setArrows(arrows+ARROWS_BONUS);
		break;
	case BOMB_GIFT:
		location->movePoint(p,ch);
		setScore(score-BOMB_BONUS);
		break;
	case ' ':
		location->movePoint(p,ch);	break;
	}
}