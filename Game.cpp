#include "Game.h"
#include "general.h"
#include "Point.h"
#include <Windows.h>
#include <conio.h>
#include <process.h>

const int ESC=27;
void Game::run(char** argv)
{
	system("cls");
	if((numOfFiles==0)||(numOfFiles>5)||(!organizeFiles(argv)))
	{
		cout << "Usage:\tHunger.exe <Board File> <Option>=<File> ..." << endl << endl;
		cout << "Options:" << endl;
		cout << "\tC1\tFile for the 1st file player" << endl;
		cout << "\tC2\tFile for the 2nd file player" << endl;
		cout << "\tC3\tFile for the 3rd file player" << endl;
		cout << "\tE\tFile for gifts to throw on board" << endl << endl;
		cout << "*\tEvery other file or file without an option will be considered as a board file" << endl;
		cout << "**\tEvery option can be sent only once" << endl;
		cout << "***\tNote: You must send a borad file to the game!!!" << endl;
	}
	else
	{
		system("cls");
		play();
	}
	cin.get();
}

bool Game::organizeFiles(char** argv)
{
	bool res=true;
	int i;
	for(i=0;i<NUM_OF_FILE_TYPES;++i)
	{
		files[i]=NULL;
	}
	i=1;
	while((i<=numOfFiles)&&(res))
	{
		switch(argv[i][0])
		{
		case 'e':
		case 'E':
			if(argv[i][1]=='=')
			{
				res=insertToFiles(E,argv[i]+2);
			}
			else
			{
				res=insertToFiles(BoardFile,argv[i]);
			}
			break;
		case 'c':
		case 'C':
			if((argv[i][1]=='1')||(argv[i][1]=='2')||(argv[i][1]=='3'))
			{
				if((argv[i][1]=='1')&&(argv[i][2]=='='))
				{
					res=insertToFiles(C1,argv[i]+3);
				}
				else if((argv[i][1]=='2')&&(argv[i][2]=='='))
				{
					res=insertToFiles(C2,argv[i]+3);
				}
				else if((argv[i][1]=='3')&&(argv[i][2]=='='))
				{
					res=insertToFiles(C3,argv[i]+3);
				}
				else
				{
					res=insertToFiles(BoardFile,argv[i]);
				}
			}
			else
			{
				res=insertToFiles(BoardFile,argv[i]);
			}
			break;
		default: res=insertToFiles(BoardFile,argv[i]);
		}
		i++;
	}
	char* fileTypes[]={"Board","C1","C2","C3","E"};
	cout << "The game loaded the following files:" << endl;
	for(i=0;i<NUM_OF_FILE_TYPES;++i)
	{
		cout << fileTypes[i] << "\t";
		if(files[i])
		{
			cout << files[i] << endl;
		}
		else
		{
			cout << "--" << endl;
		}
	}
	if(res)
	{
		Sleep(4000);
	}
	else
	{
		cout << "\nThere was a problem processing the sent files, Follow the usage!" << endl << endl;
	}
	return res;
}

bool Game::insertToFiles(FileType type,char* str)
{
	bool res;
	ifstream file;
	if(files[type]==NULL)
	{
		file.open(str,ifstream::in);
		if(file)
		{
			files[type]=str;
			file.close();
			res=true;
		}
		else
		{
			res=false;
		}
	}
	else
	{
		res=false;
	}
	return res;
}

void Game::play()
{
	bool stopGame=false,validBoard;
	b.setPList(pList);
	b.setAList(aList);
	validBoard=b.readFile(files);
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
		cout << "The Board file isn't valid or doesn't exist" << endl;
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
		if(playCounter%PLAYER_ROUND_MOVE==0)
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