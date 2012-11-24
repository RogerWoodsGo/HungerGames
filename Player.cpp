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
	char nextPlace;
	Point p;
	if(rand()%7==0)
		setDirection();
	location->getNextMove(direct,p);
	(char)nextPlace=location->getBoard()->getContent(p);
	switch (nextPlace)
	{
	case (char)(178):
		setDirection();	break;
	/*case 'F':		break;
	case 'A':		break;
	case 'P':		break;
	case 'B':		break;
	default:*/
	case ' ':
		location->movePoint(p,ch);
		break;
		//default: setDirection();
	}
}