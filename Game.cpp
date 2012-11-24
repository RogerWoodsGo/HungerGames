#include "Game.h"
#include "Board.h"
#include "general.h"
#include "Point.h"
#include <Windows.h>
#include <conio.h>
#include <process.h>

const int ESC=27;

void Game::play(char* fileName)
{
	Board b;
	bool answerPressed=false,stopGame=false,validBoard=false;
	char answer;
	PlayerList pList(b);
	Point item(0,0);
	b.readFile(fileName,pList);
	validBoard=b.checkBoard(pList);
	if (validBoard)
	{
		b.printText(pList);
		while(!stopGame)
		{
			movePlayers(pList);
			//moveArrows(aList);
			b.throwGifts();
			//updateScoreBoard(pList);
			if(_kbhit()&&_getch()==ESC)
			{
				system("cls");
				cout << "Do you want to stop the game (y/n)? ";
				while(!answerPressed)
				{
					if(_kbhit())
					{
						answer=_getch();
						if(answer=='y')
						{
							answerPressed=true;
							cout << "\nThank you for playing our hunger game" << endl;
							stopGame=true;
						}
						else if(answer=='n')
						{
							answerPressed=true;
							system("cls");
							b.printText(pList);
						}
					}
				}
				answerPressed=false;
			}
			Sleep(1);
		}

	}
	else 
	{
		cout << "The text file isn't valid" << endl;
	}
	//item.setPlace(24,0);
	//item.draw(' ');
	//cout << "numOfPlayersOnBoard=" << numOfPlayersOnBoard << " ,scoreBoardPlace=" << x << "," << y << endl;
	//p=(pList.getHead())->getPlayer()->getPlace();
	//p->getPlace(x,y);
	//cout << x << "," << y << endl;
}

void Game::movePlayers(PlayerList& pList)
{
	PlayerItem* curr=pList.getHead();
	while(curr!=0)
	{
		curr->getPlayer()->move();
		curr=curr->getNext();
	}
}