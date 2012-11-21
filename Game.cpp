#include "Game.h"
#include "general.h"
#include "Point.h"

void Game::play(char* fileName)
{
	Board b;
	PlayerList pList(b);
	//Point* p;
	int x,y;
	Point item(0,0);
	b.readFile(fileName,pList);
	b.printText(pList);

	movePlayers(pList,b);

	item.setPlace(24,0);
	item.draw(' ');
	//cout << "numOfPlayersOnBoard=" << numOfPlayersOnBoard << " ,scoreBoardPlace=" << x << "," << y << endl;
	//p=(pList.getHead())->getPlayer()->getPlace();
	//p->getPlace(x,y);
	//cout << x << "," << y << endl;
}

void Game::movePlayers(PlayerList& pList,Board& b)
{
	Direction direct;
	//Point* p;
	//int x,y;
	char nextPlace;
	PlayerItem* curr=pList.getHead();
	while(curr!=0)
	{
		direct=curr->getPlayer()->getDirect();
		nextPlace=curr->getPlayer()->getPlace()->getNextMove(b,direct);
		switch (nextPlace)
		{
		case 'W':		break;
		case 'F':		break;
		case 'A':		break;
		case 'P':		break;
		case 'B':		break;
		}
		curr=curr->getNext();
	}
}

void Game::throwGifts()
{

}