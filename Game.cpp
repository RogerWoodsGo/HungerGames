#include "Game.h"

void Game::play(char* fileName)
{
	Board b;
	PlayerList pList;
	Point* p;//
	char** text;
	int numOfPlayersOnBoard,x,y;
	Point scoreBoardPlace,item(0,0);
	text=new char*[HEIGHT];
	for(int i=0;i<HEIGHT;i++)
		text[i]=new char[WIDTH+1];
	b.readFile(fileName,text,numOfPlayersOnBoard,scoreBoardPlace,pList);
	b.printText(text,pList);

	movePlayers(pList,b);

	item.setPlace(0,24);
	item.draw(' ');
	scoreBoardPlace.getPlace(x,y);
	cout << "numOfPlayersOnBoard=" << numOfPlayersOnBoard << " ,scoreBoardPlace=" << x << "," << y << endl;
	p=(pList.getHead())->getPlayer()->getPlace();
	p->getPlace(x,y);
	cout << x << "," << y << endl;

	for(int i=0;i<HEIGHT;i++)
		delete text[i];
	delete []text;
}

void Game::movePlayers(PlayerList& pList,Board& b)
{
	Direction direct;
	Point* p;
	int x,y;
	char nextPlace;
	PlayerItem* curr=pList.getHead();
	while(curr!=0)
	{
		direct=curr->getPlayer()->getDirect();
		nextPlace=curr->getPlayer()->getPlace()->getNextMove(b.getText(),direct);
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