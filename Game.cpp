#include "Game.h"
#include "general.h"
#include "Point.h"
#include "HumanPlayer.h"
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
			moveArrows();
			b.throwGifts();
			movePlayers();
			pList.setContent();
			pList.print();
			shootArrows();
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

void Game::movePlayers()const
{
	PlayerItem* curr=pList.getHead();
	while(curr!=0)
	{
		if(curr->getPlayer()->getTimeToMove()%PLAYER_ROUND_MOVE==0)
		{
			if(typeid(*(curr->getPlayer())).name()==typeid(HumanPlayer).name())
			{
				curr->getPlayer()->setDirection(lastDirection);
			}
			curr->getPlayer()->tryToMove();
		}
		curr->getPlayer()->updateTimeToMove();
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

void Game::shootArrows()
{
	PlayerItem* curr=pList.getHead();
	while(curr!=0)
	{
		if(curr->getPlayer()->timeToShoot())
		{
			if(typeid(*(curr->getPlayer())).name()==typeid(HumanPlayer).name())
			{
				curr->getPlayer()->setShootingOption(lastArrowType);
				lastArrowType=0;
			}
			else
			{
				curr->getPlayer()->setShootingOption((rand()%3)+1);
			}
			curr->getPlayer()->shoot(aList);
		}
		curr->getPlayer()->updateTimeToShoot();
		curr=curr->getNext();
	}
}

bool Game::checkPressedKeys()
{
	bool answerPressed=false,stopGame=false;
	char answer;
	switch(_getch())
	{
	case 'a':
	case 'A':
		lastDirection=Left;
		break;
	case 'd':
	case 'D':
		lastDirection=Right;
		break;
	case 'w':
	case 'W':
		lastDirection=Up;
		break;
	case 's':
	case 'S':
		lastDirection=Down;
		break;
	case 'i':
	case 'I':
		lastArrowType=1;
		break;
	case 'o':
	case 'O':
		lastArrowType=2;
		break;
	case 'p':
	case 'P':
		lastArrowType=3;
		break;
	case ESC:
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
		break;
	default: stopGame=false;
	}
	fflush(stdin);
	return stopGame;
}