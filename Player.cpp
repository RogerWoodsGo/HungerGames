#include "Player.h"
#include "Board.h"

void Player::setShootingOption(ArrowType arrow)
{
	arrowToShoot=arrow;
}

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
}

bool Player::shoot(ArrowList& aList)
{
	Point p;
	char nextPlace,arrowChar=' ';
	int x,y,numOfBombingArrows,numOfPassingArrows,numOfRegularArrows;
	bool arrowShot=false;
	if(direct!=Center)
	{
		location->getNextMove(direct,p);
		nextPlace=location->getBoard()->getContent(p);
		//We don't shoot arrows near a wall or another arrow because we want to see the arrow being shot before it hits something
		if((nextPlace!=WALL)&&(nextPlace!=ARROW))
		{
			getArrows(numOfBombingArrows,numOfPassingArrows,numOfRegularArrows);
			if((numOfBombingArrows>0)&&(arrowToShoot==Bombing))
			{
				decreaseArrows(1,0,0);
				arrowChar=BOMBING_ARROW;
				arrowShot=true;
				arrowToShoot=None;
			}
			if((numOfPassingArrows>0)&&(arrowToShoot==Passing))
			{
				decreaseArrows(0,1,0);
				arrowChar=PASSING_ARROW;
				arrowShot=true;
				arrowToShoot=None;
			}
			if((numOfRegularArrows>0)&&(arrowToShoot==Regular))
			{
				decreaseArrows(0,0,1);
				arrowChar=REGULAR_ARROW;
				arrowShot=true;
				arrowToShoot=None;
			}
			if(arrowChar!=' ')
			{
				if(nextPlace==PLAYER)
				{
					location->getBoard()->arrowHitsPlayer(p);
				}
				else
				{
					p.getPlace(x,y);
					aList.add(x,y,direct,arrowChar);
					aList.getHead()->getArrow()->getLocation()->setBoard(location->getBoard());
					aList.getHead()->getArrow()->setGiftSteppedOn(nextPlace);
					location->getBoard()->setContent(p,ARROW);
				}
			}
		}
	}
	return arrowShot;
}