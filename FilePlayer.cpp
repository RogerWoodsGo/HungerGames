#include "FilePlayer.h"
#include "Board.h"
#include "general.h"

void FilePlayer::tryToMove(int playCounter)
{
	int vectorLimit,i=0;
	char nextPlace,ch;
	Point nextPoint;
	if((*eventMap)[playCounter])
	{
		vector<char> eventVector=*((*eventMap)[playCounter]);
		vector<char>::iterator itr=eventVector.begin();
		vector<char>::iterator itrEnd=eventVector.end();
		vectorLimit=eventVector.size();
		while((i<VECTOR_LIMIT)&&(itr!=itrEnd))
		{
			ch=*itr;
			switch(ch)
			{
			case 'a':
			case 'A':
				setDirection(Left);
				break;
			case 'd':
			case 'D':
				setDirection(Right);
				break;
			case 'w':
			case 'W':
				setDirection(Up);
				break;
			case 's':
			case 'S':
				setDirection(Down);
				break;
			case 'i':
			case 'I':
				setShootingOption(Bombing);
				break;
			case 'o':
			case 'O':
				setShootingOption(Passing);
				break;
			case 'p':
			case 'P':
				setShootingOption(Regular);
				break;
			}
			itr++;
			i++;
		}
	}
	if((playCounter%PLAYER_ROUND_MOVE==0)&&(direct!=Center))
	{
		location->getNextMove(direct,nextPoint);
		nextPlace=location->getBoard()->getContent(nextPoint);
		if(nextPlace!=WALL)
		{
			move();
		}
	}
}

void FilePlayer::tryToShoot(ArrowList& aList,int playCounter)
{
	shoot(aList);
}
FilePlayer::~FilePlayer()
{
	location->getBoard()->freeMap(eventMap);
	delete eventMap;
}