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
	bool answerPressed=false,stopGame=false,validBoard;
	char answer;
	PlayerList pList;
	Point item(0,0);
	b.readFile(fileName,pList);
	validBoard=b.checkBoard();
	if (validBoard)
	{
		b.printText();
		while((!stopGame)&&(!isThereAWinner(pList)))
		{
			movePlayers(pList);
			//moveArrows(aList);
			b.throwGifts();
			b.printScoreBoard();
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
							stopGame=true;
						}
						else if(answer=='n')
						{
							answerPressed=true;
							system("cls");
							b.printText();
						}
					}
				}
				answerPressed=false;
			}
			Sleep(1);
		}
		if(stopGame==true)
		{
			cout << "\nThank you for playing our hunger game" << endl;
		}
		else
		{
			if((pList.getHead()!=0)&&(pList.getHead()->getPlayer()->getScore()>0))
			{
				system("cls");
				cout << pList.getHead()->getPlayer()->getChar() << " is the winner!!!" << endl;
			}
			else
			{
				system("cls");
				cout << "Game over. Thank you for playing our hunger game" << endl;
			}
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

bool Game::isThereAWinner(PlayerList& pList)
{
	int score;
	bool winnerFound=false;
	PlayerItem* curr = pList.getHead(),*next;
	while((curr!=0)&&(!winnerFound))
	{
		next=curr->getNext();
		score=curr->getPlayer()->getScore();
		if(score<=0)
		{
			curr->getPlayer()->getPlace()->draw(' ');
			pList.Remove(*(curr->getPlayer()));
		}
		curr=next;
		if(pList.getHead()->getNext()==0)
		{
			winnerFound=true;
		}
	}
	return winnerFound;
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