#include "Board.h"
#include "general.h"

Board::Board()
{
	text=new char*[HEIGHT];
	for(int i=0;i<HEIGHT;i++)
		text[i]=new char[WIDTH];
	numOfComputerPlayersOnBoard=0;
	numOfHumanPlayersOnBoard=0;
	scoreBoardPlace.setPlace(0,0);
}

void Board::readFile(char* fileName)
{
	FILE* f;
	char ch;
	bool OWasFound=false;
	f=fopen(fileName,"r");
	for(int i=0;i<HEIGHT;i++)
	{
		for(int j=0;j<WIDTH;j++)
		{
			ch=(char)(fgetc(f));
			switch(ch)
			{
			case 'W':
				text[i][j]=WALL;
				break;
			case 'H':
				if(numOfHumanPlayersOnBoard<MAX_NUM_OF_HUMAN_PLAYERS)
				{
					numOfHumanPlayersOnBoard++;
					text[i][j]=PLAYER;
					pList->Add(i,j,HUMAN_PLAYER);
					pList->getHead()->getPlayer()->getLocation()->setBoard(this);
				}
				else text[i][j]=' ';
				break;
			case PLAYER:
				if(numOfComputerPlayersOnBoard<MAX_NUM_OF_COMPUTER_PLAYERS)
				{
					numOfComputerPlayersOnBoard++;
					text[i][j]=PLAYER;
					pList->Add(i,j,numOfComputerPlayersOnBoard);
					pList->getHead()->getPlayer()->getLocation()->setBoard(this);
				}
				else text[i][j]=' ';
				break;
			case 'O':
				if(!OWasFound)
				{
					OWasFound=true;
					scoreBoardPlace.setPlace(i,j);
				}
				text[i][j]=' ';
				break;
			default: text[i][j]=' ';
			}
		}
		fgetc(f);
	}
	fclose(f);
}

bool Board::checkBoard()
{
	int x,y;
	bool validBoard=true,validPlace=true;
	Point playerPlace,nextPlace;
	PlayerItem* curr=pList->getHead();
	scoreBoardPlace.getPlace(x,y);
	if((x<MIN_VALID_BOARD_PLACE_X)||(x>MAX_VALID_BOARD_PLACE_X)||(y<MIN_VALID_BOARD_PLACE_Y)||(y>MAX_VALID_BOARD_PLACE_Y))
	{
		validBoard=false;
		cout << "Illegal Text file" << endl;
	}
	if(validBoard)
	{
		while(curr!=0)
		{
			curr->getPlayer()->getLocation()->getPlace(x,y);
			playerPlace.setPlace(x,y);
			if((isPointInScoreBoard(playerPlace)))
			{
				setContent(playerPlace,' '); //remove player from board
				validPlace=randomLocation(playerPlace);
				if(!validPlace)
				{
					cout << "Valid place wasn't found" << endl;
					validBoard=false;
				}
				else
				{
					playerPlace.getPlace(x,y);
					curr->getPlayer()->getLocation()->setPlace(x,y);
					setContent(playerPlace,PLAYER);
				}
			}
			curr=curr->getNext();
		}
	}
	if(validBoard)
	{
		while(numOfComputerPlayersOnBoard+numOfHumanPlayersOnBoard<MIN_NUM_OF_PLAYERS_ON_BOARD)
		{
			validPlace=randomLocation(playerPlace);
			if(!validPlace)
			{
				cout << "Valid place didn't found" << endl;
				validBoard=false;
			}
			else
			{
				numOfComputerPlayersOnBoard++;
				playerPlace.getPlace(x,y);
				pList->Add(x,y,numOfComputerPlayersOnBoard);
				pList->getHead()->getPlayer()->getLocation()->setBoard(this);
				setContent(playerPlace,PLAYER);
			}
		}
	}
	if(validBoard)
	{
		scoreBoardPlace.getPlace(x,y);
		y--;
		x--;
		for(int i=y;i<y+SCORE_BOARD_WIDTH;i++)
		{
			text[x][i]=WALL;
			text[x+(SCORE_BOARD_HEIGHT-1)][i]=WALL;
		}
		for(int j=x+1;j<x+SCORE_BOARD_HEIGHT;j++)
		{
			text[j][y]=WALL;
			text[j][y+(SCORE_BOARD_WIDTH-1)]=WALL;
		}
	}
	return validBoard;
}

void Board::printText()
{
	for(int i=0;i<HEIGHT;i++)
	{
		for(int j=0;j<WIDTH;j++)
		{
			if((text[i][j]==PLAYER)||(text[i][j]==ARROW))
			{
				cout << ' ';
			}
			else
			{
				cout << text[i][j];
			}
		}
		cout << endl;
	}
	pList->Print();
	aList->Print();
	printScoreBoard();
}

char Board::getContent(Point& p)
{
	int x,y;
	p.getPlace(x,y);
	return text[x][y];
}

void Board::setContent(Point& p,char ch)
{
	int x,y;
	p.getPlace(x,y);
	text[x][y]=ch;
}

bool Board::randomLocation(Point& p)
{
	Point newLocation;
	char newLocationContent;
	bool newLocationWasFound=false;
	int x,y,timeSearchedForLocation=0;
	while((!newLocationWasFound)&&(timeSearchedForLocation<=NUM_OF_TRIES_TO_FIND_NEW_LOCATION))
	{
		x=rand()%HEIGHT;
		y=rand()%WIDTH;
		newLocation.setPlace(x,y);
		newLocationContent=getContent(newLocation);
		if((newLocationContent==' ')&&(!isPointInScoreBoard(newLocation)))
		{
			newLocationWasFound=true;
			p.setPlace(x,y);
		}
		timeSearchedForLocation++;
	}
	if(!newLocationWasFound)
	{
		for(x=0;x<HEIGHT;x++)
		{
			for(y=0;y<WIDTH;y++)
			{
				newLocation.setPlace(x,y);
				newLocationContent=getContent(newLocation);
				if((newLocationContent==' ')&&(!isPointInScoreBoard(newLocation)))
				{
					newLocationWasFound=true;
					p.setPlace(x,y);
				}
			}
		}

	}
	return newLocationWasFound;
}

bool Board::isPointNearAPlayer(Point& p)
{
	PlayerItem* curr=pList->getHead();
	int x,y,playerX,playerY;
	p.getPlace(x,y);
	bool isPointNearThePlayer=false;
	while((curr!=0)&&(!isPointNearThePlayer))
	{
		curr->getPlayer()->getLocation()->getPlace(playerX,playerY);
		playerX-=DISTANCE_BETWEEN_ITEM_TO_PLAYER;
		playerY-=DISTANCE_BETWEEN_ITEM_TO_PLAYER;
		if((x-playerX<=DISTANCE_BETWEEN_ITEM_TO_PLAYER+2)&&(y-playerY<=DISTANCE_BETWEEN_ITEM_TO_PLAYER+2)
			&&(x-playerX>=DISTANCE_BETWEEN_ITEM_TO_PLAYER-2)&&(y-playerY>=DISTANCE_BETWEEN_ITEM_TO_PLAYER-2))
		{
			isPointNearThePlayer=true;
		}
		curr=curr->getNext();
	}
	return isPointNearThePlayer;
}

void Board::throwGifts()
{
	Point giftLocation;
	int chance=(rand()%GIFT_CHANCE)+1;//1-20
	//Bomb 0.05
	if(chance%int((1/BOMB_CHANCE))==0)//20
	{
		if(randomLocation(giftLocation))
		{
			if(!isPointNearAPlayer(giftLocation))
			{
				setContent(giftLocation,BOMB_GIFT);
				giftLocation.draw(BOMB_GIFT);
			}
		}
	}
	//Arrow 0.1
	if(chance%int((1/ARROW_CHANCE))==0)//10,20
	{
		if(randomLocation(giftLocation))
		{
			if(!isPointNearAPlayer(giftLocation))
			{
				setContent(giftLocation,ARROW_GIFT);
				giftLocation.draw(ARROW_GIFT);
			}
		}
	}
	//Food 0.2
	if(chance%int((1/FOOD_CHANCE))==0)//5,10,15,20
	{
		if(randomLocation(giftLocation))
		{
			if(!isPointNearAPlayer(giftLocation))
			{
				setContent(giftLocation,FOOD_GIFT);
				giftLocation.draw(FOOD_GIFT);
			}
		}
	}
}

bool Board::isPointInScoreBoard(Point& p)
{
	int SBx,SBy,x,y;
	scoreBoardPlace.getPlace(SBx,SBy);
	SBx--;
	SBy--;
	p.getPlace(x,y);
	if((x-SBx<SCORE_BOARD_HEIGHT)&&(y-SBy<SCORE_BOARD_WIDTH)&&(x-SBx>=0)&&(y-SBy>=0))
	{
		return true;
	}
	else return false;
}

void Board::printScoreBoard()
{
	int SBx,SBy,x,y,score,numOfRegularArrows,numOfPassingArrows,numOfBombingArrows;
	char ch;
	Point p;
	PlayerItem* curr=pList->getHead();
	scoreBoardPlace.getPlace(SBx,SBy);
	while(curr!=0)
	{
		x=SBx;
		y=SBy;
		scoreBoardPlace.getPlace(x,y);
		curr->getPlayer()->getArrows(numOfRegularArrows,numOfPassingArrows,numOfBombingArrows);
		score=curr->getPlayer()->getScore();
		ch=curr->getPlayer()->getChar();
		x+=(ch-1)*2;
		p.setPlace(x,y);
		p.draw(ch);//Draw the player icon
		if(numOfRegularArrows>9)
		{
			cout << '*';
		}
		else
		{
			cout << numOfRegularArrows;
		}
		if(numOfPassingArrows>9)
		{
			cout << '*';
		}
		else
		{
			cout << numOfPassingArrows;
		}
		if(numOfBombingArrows>9)
		{
			cout << '*';
		}
		else
		{
			cout << numOfBombingArrows;
		}
		cout << " ";
		if(score>9999)
		{
			cout << score;
		}
		else if(score>999)
		{
			cout << " " << score;
		}
		else if(score>99)
		{
			cout << "  " << score;
		}
		else if(score>9)
		{
			cout << "   " << score;
		}
		else if(score>0)
		{
			cout << "    " << score;
		}
		else
		{
			cout << "    0";
		}
		curr=curr->getNext();
	}
}

void Board::playerFight(Point& p)
{
	int x,y,playerX,playerY,numOfMaxPlayers=0,max=0,score;
	PlayerItem* curr=pList->getHead();
	p.getPlace(x,y);
	while(curr!=0)
	{
		curr->getPlayer()->getLocation()->getPlace(playerX,playerY);
		if((x==playerX)&&(y==playerY))
		{
			if(curr->getPlayer()->getScore()>max)
			{
				max=curr->getPlayer()->getScore();
				numOfMaxPlayers=1;
			}
			else if(curr->getPlayer()->getScore()==max)
			{
				numOfMaxPlayers++;
			}
		}
		curr=curr->getNext();
	}
	curr=pList->getHead();
	while(curr!=0)
	{
		curr->getPlayer()->getLocation()->getPlace(playerX,playerY);
		if((x==playerX)&&(y==playerY))
		{
			if(curr->getPlayer()->getScore()<max)
			{
				score=curr->getPlayer()->getScore();
				curr->getPlayer()->setScore(score-LOW_POWER_PLAYER);
			}
			else if((curr->getPlayer()->getScore()==max)&&(numOfMaxPlayers==NUM_OF_PLAYERS_WITH_MAX_SCORE))
			{
				score=curr->getPlayer()->getScore();
				curr->getPlayer()->setScore(score-HIGH_POWER_PLAYER);
			}
			else if((curr->getPlayer()->getScore()==max)&&(numOfMaxPlayers>NUM_OF_PLAYERS_WITH_MAX_SCORE))
			{
				score=curr->getPlayer()->getScore();
				curr->getPlayer()->setScore(score-EQUAL_POWER_PLAYER);
			}
		}
		curr=curr->getNext();
	}
}

void Board::arrowHitsPlayer(Point& p)
{
	PlayerItem* pCurr=pList->getHead();
	ArrowItem* aCurr=aList->getHead();
	int x,y,playerX,playerY,arrowX,arrowY,score;
	p.getPlace(x,y);
	while(pCurr!=0)
	{
		pCurr->getPlayer()->getLocation()->getPlace(playerX,playerY);
		if((x==playerX)&&(y==playerY))
		{
			score=pCurr->getPlayer()->getScore();
			pCurr->getPlayer()->setScore(score-ARROW_HIT_PLAYER);
		}
		pCurr=pCurr->getNext();
	}
	while(aCurr!=0)
	{
		aCurr->getArrow()->getLocation()->getPlace(arrowX,arrowY);
		if((x==arrowX)&&(y==arrowX))
		{
			aCurr->getArrow()->setKillArrow();
		}
		aCurr=aCurr->getNext();
	}
}

Board::~Board()
{
	for(int i=0;i<HEIGHT;i++)
	{
		delete text[i];
	}
	delete []text;
}