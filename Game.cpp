#include "Game.h"

void Game::play(char* fileName)
{
	Board b;
	PlayerList pList;
	char text[HEIGHT][WIDTH+1];
	int numOfPlayersOnBoard,x,y;
	Point scoreBoardPlace,item(0,0);
	b.readFile(fileName,text,numOfPlayersOnBoard,scoreBoardPlace,pList);
	b.printText(text,pList);
	item.setPlace(0,24);
	item.draw('T');
	scoreBoardPlace.getPlace(x,y);
	cout << "numOfPlayersOnBoard=" << numOfPlayersOnBoard << " ,scoreBoardPlace=" << x << "," << y << endl;
}