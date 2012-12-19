#include "Arrow.h"
#include "ArrowItem.h"
#include "Board.h"

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
	else
	{
		currentPlace=location->getBoard()->getContent(*location);
		if((currentPlace==REGULAR_ARROW)||(currentPlace==PASSING_ARROW)||(currentPlace==BOMBING_ARROW))
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
			if((nextPlace==REGULAR_ARROW)||(nextPlace==PASSING_ARROW)||(nextPlace==BOMBING_ARROW))
			{
				setGiftSteppedOn(' ');//Not saving the arrow I am stepping on
			}
			else
			{
				setGiftSteppedOn(nextPlace);//Saving the gift on the next step
			}
			location->movePoint(p,ch);
		}
	}
}