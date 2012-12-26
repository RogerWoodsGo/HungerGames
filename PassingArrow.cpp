#include "PassingArrow.h"
#include "ArrowItem.h"
#include "Board.h"

void PassingArrow::move()
{
	char nextPlace,currentPlace;
	Point nextPoint;
	int x,y;
	currentPlace=location->getBoard()->getContent(*location);
	if((currentPlace==ARROW)||(currentPlace==WALL))
	{
		location->draw(giftSteppedOn);//Drawing the gift I just stepped on
		location->getBoard()->setContent(*location,giftSteppedOn);//Returning the gift I just stepped on to the text
	}
	location->getNextMove(direct,nextPoint);
	nextPoint.getPlace(x,y);//Get the new place for arrow
	location->setPlace(x,y);//Set the new place for arrow
	nextPlace=location->getBoard()->getContent(*location);
	if(nextPlace==PLAYER)
	{
		location->getBoard()->arrowHitsPlayer(*location);
	}
	else
	{
		if(nextPlace==WALL)
		{
			setGiftSteppedOn(WALL);//Saving the wall I am stepping on
		}
		else if(nextPlace==ARROW)
		{
			setGiftSteppedOn(' ');//Not saving the arrow I am stepping on
		}
		else
		{
			setGiftSteppedOn(nextPlace);//Saving the gift on the next step
			location->getBoard()->setContent(nextPoint,ARROW);//Write the arrow to the text	
		}
		location->draw(symbol);//Draw arrow on screen
	}
}