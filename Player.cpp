#include "Player.h"
#include "PlayerItem.h"
#include "Board.h"

Direction Player::randomDirection()
{
	return (Direction)(rand()%4);
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
	if(rand()%7==0)
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
		setScore(score+200);
		break;
	case ARROW_GIFT:
		location->movePoint(p,ch);
		setArrows(arrows+3);
		break;
	case BOMB_GIFT:
		location->movePoint(p,ch);
		setScore(score-750);
		break;
	case ' ':
		location->movePoint(p,ch);	break;
	}
}