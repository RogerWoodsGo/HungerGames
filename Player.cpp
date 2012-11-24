#include "Player.h"
#include "PlayerItem.h"
#include "Board.h"
#include "general.h"

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
	(char)nextPlace=location->getBoard()->getContent(p);
	switch (nextPlace)
	{
	case WALL:
		setDirection();	break;
	case FOOD:
		location->movePoint(p,ch);
		setScore(score+200);
		break;
	case ARROW:
		location->movePoint(p,ch);
		setArrows(arrows+3);
		break;
	case 'P':
		location->movePoint(p,ch);
		location->getBoard()->playerFight(*location);
		break;
	case BOMB:
		location->movePoint(p,ch);
		setScore(score-50);
		break;
	case ' ':
		location->movePoint(p,ch);	break;
	}
}