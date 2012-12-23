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
	int playCounter=0;
	b.setPList(pList);
	b.setAList(aList);
	b.readFile(fileName);
	validBoard=b.checkBoard();
	if(validBoard)
	{
		b.printText();
		while((!stopGame)&&(!isThereAWinner()))
		{
			playCounter++;
			moveArrows();
			b.throwGifts();
			if(playCounter%PLAYER_ROUND_MOVE==0)
			{
				movePlayers();
			}
			if(playCounter%(PLAYER_ROUND_MOVE*4)==0)//A player can shoot an arrow every 4th move so its every 8th arrow move because arrows are twice as fast as the player
			{
				shootArrows();
			}
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
				cout << pList.getHead()->getPlayer()->getChar() << " is the winner!!! Thank you for playing our hunger game." << endl;
			}
			else
			{	
				cout << "Game over. Thank you for playing our hunger game." << endl;
			}
		}
	}
	else 
	{
		cout << "The text file isn't valid" << endl;
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

void Game::movePlayers()
{
	PlayerItem* curr=pList.getHead();
	while(curr!=0)
	{
		if(typeid(*(curr->getPlayer())).name()==typeid(HumanPlayer).name())
		{
			curr->getPlayer()->setDirection(lastDirection);
		}
		curr->getPlayer()->tryToMove();
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
			aList.Remove(*(curr->getArrow()));
			curr=next;
		}
	}
}

void Game::shootArrows()
{
	PlayerItem* curr=pList.getHead();
	Point p;
	char nextPlace,arrowChar;
	int x,y,numOfArrows,numOfRegularArrows,numOfPassingArrows,numOfBombingArrows;
	Direction direct;
	while(curr!=0)
	{
		numOfArrows=curr->getPlayer()->getArrows();
		if(numOfArrows>0)
		{
			direct=curr->getPlayer()->getDirect();
			if(direct!=Center)
			{
				curr->getPlayer()->getLocation()->getNextMove(direct,p);
				nextPlace=b.getContent(p);
				//We don't shoot arrows near a wall or another arrow because we want to see the arrow being shot before it hits something
				if((nextPlace!=WALL)&&(nextPlace!=ARROW))
				{
					curr->getPlayer()->getArrows(numOfRegularArrows,numOfPassingArrows,numOfBombingArrows);
					if(numOfBombingArrows>0)
					{
						curr->getPlayer()->decreaseArrows(0,0,1);
						arrowChar=BOMBING_ARROW;
					}
					else if(numOfPassingArrows>0)
					{
						curr->getPlayer()->decreaseArrows(0,1,0);
						arrowChar=PASSING_ARROW;
					}
					else
					{
						curr->getPlayer()->decreaseArrows(1,0,0);
						arrowChar=REGULAR_ARROW;
					}
					if(nextPlace==PLAYER)
					{
						b.arrowHitsPlayer(p);
					}
					else
					{
						p.getPlace(x,y);
						aList.Add(x,y,direct,arrowChar);
						aList.getHead()->getArrow()->getLocation()->setBoard(&b);
						aList.getHead()->getArrow()->setGiftSteppedOn(nextPlace);
						b.setContent(p,ARROW);
					}
				}
			}
		}
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
		break;/*
			  case 'i':
			  case 'I':

			  break;
			  case 'o':
			  case 'O':

			  break;
			  case 'p':
			  case 'P':

			  break;*/
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