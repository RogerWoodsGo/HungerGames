#include "Arrow.h"
#include "ArrowItem.h"
#include "Board.h"
#include "general.h"

void Arrow::move()
{
	char nextPlace,currentPlace;
	Point p;
	location->getNextMove(direct,p);
	nextPlace=location->getBoard()->getContent(p);
	if(nextPlace==PLAYER)
	{
		location->getBoard()->arrowHitsPlayer(*location);
	}
	else //if((nextPlace==ARROW_GIFT)||(nextPlace==BOMB_GIFT)||(nextPlace==FOOD_GIFT)||(nextPlace==' '))
	{
		currentPlace=location->getBoard()->getContent(*location);
		if(currentPlace==ARROW)
		{
			location->draw(giftSteppedOn);//Drawing the gift I just stepped on
			location->getBoard()->setContent(*location,giftSteppedOn);//Returning the gift I just stepped on to the text
		}
		if(nextPlace==WALL)
		{
			setKillArrow();
		}
		else
		{
			if(nextPlace==ARROW)
			{
				setGiftSteppedOn(' ');//Not saving the arrow I am stepping on
			}
			else
			{
				setGiftSteppedOn(nextPlace);//Saving the gift on the next step
			}
			location->movePoint(p,ARROW);
		}
	}
}