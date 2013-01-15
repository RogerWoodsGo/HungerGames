#include "Game.h"
#include "general.h"
#include "Point.h"
#include <Windows.h>
#include <conio.h>
#include <process.h>

void Game::run(char** argv)
{
	system("cls");
	if((numOfFiles==0)||(numOfFiles>NUM_OF_FILE_TYPES)||(!organizeFiles(argv)))
	{
		cout << "\nUsage:\tHunger.exe <Board File> <Option>=<File> ..." << endl;
		cout << "\nOptions:" << endl;
		cout << "\tC1\tFile for the 1st file player" << endl;
		cout << "\tC2\tFile for the 2nd file player" << endl;
		cout << "\tC3\tFile for the 3rd file player" << endl;
		cout << "\tE\tFile for gifts to throw on board" << endl;
		cout << "\nRules:" << endl;
		cout << "*\tYou must send one borad file to the game!!!" << endl;
		cout << "*\tA file without an option will be considered as a board file" << endl;
		cout << "*\tEvery option can be sent only once" << endl;
		cout << "*\tIn order to use C2 option you have to send a C1 file also" << endl;
		cout << "*\tIn order to use C3 option you have to send a C2 file also" << endl;
		cout << "*\tIn case you don't send an E file the gifts will be thrown randomly" << endl;
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
	cout << "\nThe game loaded the following files:" << endl;
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
	if(!files[BoardFile])
	{
		cout << "You must send one borad file to the game!!!" << endl;
		res=false;
	}
	if(res)
	{
		if(files[C1])
		{
			if((!files[C2])&&(files[C3]))
			{
				cout << "In order to use C3 option you have to send a C2 file also" << endl;
				res=false;
			}
		}
		else
		{
			if((files[C2])||(files[C3]))
			{
				cout << "In order to use C2/C3 option you have to send a C1 file also" << endl;
				res=false;
			}
		}
		Sleep(TIME_TO_REVIEW_FILES);
	}
	return res;
}

bool Game::insertToFiles(const FileType type,char* str)
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
			cout << "Error opening file: " << str << endl;
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
	ifstream giftFile;
	bool stopGame=false,validBoard;
	b.setPList(pList);
	b.setAList(aList);
	b.readFile(files);
	validBoard=b.checkBoard();
	if(validBoard)
	{
		if(files[E]!=NULL)
		{
			b.mapFile(b.getGiftMap(),files[E]);
		}
		b.printText();
		while((!stopGame)&&(!isThereAWinner()))
		{
			playCounter++;
			moveArrows();
			b.throwGifts(playCounter);
			playPlayers();
			pList.setContent();
			pList.print();
			b.printScoreBoard(playCounter);
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
			if((pList.getHead()!=NULL)&&(pList.getHead()->getPlayer()->getScore()>0))
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
	while((curr!=NULL)&&(!winnerFound))
	{
		next=curr->getNext();
		score=curr->getPlayer()->getScore();
		if(score<=0)
		{
			if(b.getHumanPlayer()==curr->getPlayer())
			{
				b.setHumanPlayer(NULL);
			}
			pList.remove(*(curr->getPlayer()));
		}
		curr=next;
		if(pList.getHead()->getNext()==NULL)
		{
			winnerFound=true;
		}
	}
	return winnerFound;
}

void Game::playPlayers()
{
	PlayerItem* curr=pList.getHead();
	while(curr!=NULL)
	{
		curr->getPlayer()->tryToMove(playCounter);
		curr->getPlayer()->tryToShoot(aList,playCounter);
		curr=curr->getNext();
	}
}

void Game::moveArrows()
{
	ArrowItem* curr=aList.getHead(),*next;
	while(curr!=NULL)
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
	else if(b.getHumanPlayer()!=NULL)
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