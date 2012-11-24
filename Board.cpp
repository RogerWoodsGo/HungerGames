#include "Board.h"

void Board::readFile(char* fileName,PlayerList& pList)
{
	FILE* f;
	char ch,**text;
	bool OWasFound=false;
	text=new char*[HEIGHT];
	for(int i=0;i<HEIGHT;i++)
		text[i]=new char[WIDTH];
	setText(text);
	f=fopen(fileName,"r");
	for(int i=0;i<HEIGHT;i++)
	{
		for(int j=0;j<WIDTH;j++)
		{
			ch=(char)(fgetc(f));
			switch(ch)
			{
			case 'W':
				text[i][j]=(char)(178);
				break;
			case 'P':
				if(numOfPlayersOnBoard<NUMBEROFPLAYERS)
				{
					text[i][j]='P';
					pList.Add(i,j);
					pList.getHead()->getPlayer()->getPlace()->setBoard(this);
					numOfPlayersOnBoard++;
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


bool Board::checkBoard(PlayerList& pList)
{
	int x,y;
	bool validBoard=true, validPlace=true;
	Point playerPlace, nextPlace;
	PlayerItem* curr=pList.getHead();
	scoreBoardPlace.getPlace(x,y);
	if((x<=0 || x>18) || (y<=0 || y>68))
	{
		validBoard=false;
		cout << "Illegal Text file" << endl;
	}
	if(validBoard)
	{
		while(curr!=0)
		{
			curr->getPlayer()->getPlace()->getPlace(x,y);
			playerPlace.setPlace(x,y);
			if((isPointInScoreBoard(playerPlace)))
			{
				setContent(playerPlace,' '); //remove player from board
				validPlace = randomLocation(playerPlace);
				if(!validPlace)
				{
					cout << "Valid place didn't found" << endl;
					validBoard = false;
				}
				else
				{
					playerPlace.getPlace(x,y);
					curr->getPlayer()->getPlace()->setPlace(x,y);
					setContent(playerPlace, 'P');
				}
			}
			curr=curr->getNext();
		}
	}
	if(validBoard)
	{
		while (numOfPlayersOnBoard < NUMBEROFPLAYERS)
		{
			validPlace = randomLocation(playerPlace);
			if(!validPlace)
			{
				cout << "Valid place didn't found" << endl;
				validBoard = false;
			}
			else
			{
				playerPlace.getPlace(x,y);
				pList.Add(x,y);
				pList.getHead()->getPlayer()->getPlace()->setBoard(this);
				setContent(playerPlace, 'P');
				numOfPlayersOnBoard++;
			}
		}
	}
	if(validBoard)
	{
		scoreBoardPlace.getPlace(x,y);
		y--;
		x--;
		for(int i=y;i<y+12;i++)
		{
			text[x][i] = (char)(178);
			text[x+6][i] = (char)(178);
		}
		for(int j=x+1;j<x+7;j++)
		{
			text[j][y] = (char)(178);
			text[j][y+11] = (char)(178);
		}
	}
	return validBoard;
}
void Board::printText(PlayerList& pList)
{
	for(int i=0;i<HEIGHT;i++)
	{
		for(int j=0;j<WIDTH;j++)
		{
			if(text[i][j]=='P')
			{
				cout << " ";
			}
			else
			{
				cout << text[i][j];
			}
		}
		cout << endl;
	}
	pList.Print();
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
	while((!newLocationWasFound)&&(timeSearchedForLocation<=30))
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

bool Board::isPointNearAPlayer(Point& p,PlayerList& pList)
{
	PlayerItem* curr=pList.getHead();
	int x,y,playerX,playerY;
	p.getPlace(x,y);
	bool isPointNearThePlayer=false;
	while((curr!=0)&&(!isPointNearThePlayer))
	{
		curr->getPlayer()->getPlace()->getPlace(playerX,playerY);
		playerX--;
		playerY--;
		if((x-playerX<=4)&&(y-playerY<=4)&&(x-playerX>=0)&&(y-playerY>=0))
		{
			isPointNearThePlayer=true;
		}
		curr=curr->getNext();
	}
	return isPointNearThePlayer;
}

void Board::throwGifts(PlayerList& pList)
{
	Point giftLocation;
	int chance=(rand()%20)+1;//1-20
	//Bomb 0.05
	if(chance%20==0)//20
	{
		if(randomLocation(giftLocation))
		{
			if(!isPointNearAPlayer(giftLocation,pList))
			{
				setContent(giftLocation,'B');
				giftLocation.draw('B');
			}
		}
	}
	//Arrow 0.1
	if(chance%10==0)//10,20
	{
		if(randomLocation(giftLocation))
		{
			if(!isPointNearAPlayer(giftLocation,pList))
			{
				setContent(giftLocation,'A');
				giftLocation.draw('A');
			}
		}
	}
	//Food 0.2
	if(chance%5==0)//5,10,15,20
	{
		if(randomLocation(giftLocation))
		{
			if(!isPointNearAPlayer(giftLocation,pList))
			{
				setContent(giftLocation,'F');
				giftLocation.draw('F');
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
	if((x-SBx<=6)&&(y-SBy<=11)&&(x-SBx>=0)&&(y-SBy>=0))
	{
		return true;
	}
	else return false;
}

void Board::printScoreBoard(PlayerList& pList)
{
	int SBx,SBy,x,y,score,arrows;
	char ch;
	Point p;
	PlayerItem* curr = pList.getHead();
	scoreBoardPlace.getPlace(SBx,SBy);
	while(curr!=0)
	{
		x=SBx;
		y=SBy;
		scoreBoardPlace.getPlace(x,y);
		arrows=curr->getPlayer()->getArrows();
		score=curr->getPlayer()->getScore();
		ch=curr->getPlayer()->getChar();
		x+=(ch-1)*2;
		p.setPlace(x,y);
		p.draw(ch);
		cout << " ";
		if(arrows>99)
		{
			cout << arrows;
		}
		else if(arrows>9)
		{
			cout << " " << arrows;
		}
		else
		{
			cout << "  " << arrows;
		}
		cout << " ";
		if(score>999)
		{
			cout << score;
		}
		else if(score>99)
		{
			cout << " " << score;
		}
		else if(score>9)
		{
			cout << "  " << score;
		}
		else
		{
			cout << "   " << score;
		}
		curr=curr->getNext();
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