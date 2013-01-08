#include "Game.h"
#include "general.h"
#include "Point.h"
#include <Windows.h>
#include <conio.h>
#include <process.h>

const int ESC=27;
void Game::run(char* fileName)
{
	system("cls");
	if(fileName==NULL)
	{
		cout << "Please specify a file" << endl;
	}
	else
	{
		play(fileName);
	}
	cin.get();
}

void Game::play(char* fileName)
{
	bool stopGame=false,validBoard;
	b.setPList(pList);
	b.setAList(aList);
	validBoard=b.readFile(fileName);
	if(validBoard)
	{
		validBoard=b.checkBoard();
	}
	if(validBoard)
	{
		b.printText();
		while((!stopGame)&&(!isThereAWinner()))
		{
			playCounter++;
			moveArrows();
			b.throwGifts();
			playPlayers();
			pList.setContent();
			pList.print();
			b.printScoreBoard();
			if(_kbhit())
			{
				stopGame=checkPressedKeys();
			}
			Sleep(SLEEP_TIME);
		}
		if(stopGame==true)
		{
			cout << endl << "Thank you for playing our hunger game." << endl;
		}
		else
		{
			system("cls");
			if((pList.getHead()!=0)&&(pList.getHead()->getPlayer()->getScore()>0))
			{
				cout << pList.getHead()->getPlayer()->getSymbol() << " is the winner!!! Thank you for playing our hunger game." << endl;
			}
			else
			{	
				cout << "Game over. Thank you for playing our hunger game." << endl;
			}
		}
	}
	else 
	{
		cout << "The text file isn't valid or doesn't exist" << endl;
	}
}

bool Game::isThereAWinner()
{
	int score;
	bool winnerFound=false;
	PlayerItem* curr=pList.getHead(),*next;
	while((curr!=0)&&(!winnerFound))
	{
		next=curr->getNext();
		score=curr->getPlayer()->getScore();
		if(score<=0)
		{
			if(b.getHumanPlayer()==curr->getPlayer())
			{
				b.setHumanPlayer(0);
			}
			pList.remove(*(curr->getPlayer()));
		}
		curr=next;
		if(pList.getHead()->getNext()==0)
		{
			winnerFound=true;
		}
	}
	return winnerFound;
}

void Game::playPlayers()
{
	PlayerItem* curr=pList.getHead();
	while(curr!=0)
	{
		if(playCounter%2==0)
		{
			curr->getPlayer()->tryToMove();
		}
		curr->getPlayer()->tryToShoot(aList,playCounter);
		curr=curr->getNext();
	}
}

void Game::moveArrows()
{
	ArrowItem* curr=aList.getHead(),*next;
	while(curr!=0)
	{
		if(curr->getArrow()->getIAmAlive()==true)
		{
			curr->getArrow()->move();
			curr=curr->getNext();
		}
		else
		{
			next=curr->getNext();
			aList.remove(*(curr->getArrow()));
			curr=next;
		}
	}
}

bool Game::checkPressedKeys()
{
	bool answerPressed=false,stopGame=false;
	char answer,ch;
	ch=_getch();
	if(ch==ESC)
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
	}
	else if(b.getHumanPlayer()!=0)
	{
		switch(ch)
		{
		case 'a':
		case 'A':
			b.getHumanPlayer()->setDirection(Left);
			break;
		case 'd':
		case 'D':
			b.getHumanPlayer()->setDirection(Right);
			break;
		case 'w':
		case 'W':
			b.getHumanPlayer()->setDirection(Up);
			break;
		case 's':
		case 'S':
			b.getHumanPlayer()->setDirection(Down);
			break;
		case 'i':
		case 'I':
			b.getHumanPlayer()->setShootingOption(Bombing);
			break;
		case 'o':
		case 'O':
			b.getHumanPlayer()->setShootingOption(Passing);
			break;
		case 'p':
		case 'P':
			b.getHumanPlayer()->setShootingOption(Regular);
			break;
		}
	}
	fflush(stdin);
	return stopGame;
}