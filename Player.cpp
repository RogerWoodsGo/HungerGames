#include "Player.h"
#include "PlayerItem.h"

Direction Player::randomDirection()
{/*
	Direction newDirection;
	switch ((rand()%4))
	{
	case Up:	newDirection=Up;	break;
	case Right:	newDirection=Right;	break;
	case Down:	newDirection=Down;	break;
	case Left:	newDirection=Left;	break;
	}
	return newDirection;*/
	return (Direction)(rand()%4);
}