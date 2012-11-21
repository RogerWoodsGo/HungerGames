#include "Player.h"

Direction Player::randomDirection()
{
	Direction newDirection;
	switch ((rand()%4)+1)
	{
	case 1:	newDirection=Up;	break;
	case 2:	newDirection=Right;	break;
	case 3: newDirection=Down;	break;
	case 4:	newDirection=Left;	break;
	}
	return newDirection;
}