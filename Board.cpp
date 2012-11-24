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
	bool validBoard=true;
	scoreBoardPlace.getPlace(x,y);
	if((x<=0 || x>18) || (y<=0 || y>68))
	{
		validBoard=false;
		cout << "Illegal Text file" << endl;
	}
	else
	{
		y=y-1;
		x=x-1;
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
	while (numOfPlayersOnBoard < NUMBEROFPLAYERS)
	{

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
	while((!newLocationWasFound)&&(timeSearchedForLocation<=50))
	{
		x=rand()%HEIGHT;
		y=rand()%WIDTH;
		newLocation.setPlace(x,y);
		newLocationContent=getContent(newLocation);
		if(newLocationContent==' ')
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
				if(newLocationContent==' ')
				{
					newLocationWasFound=true;
					p.setPlace(x,y);
				}
			}
		}

	}
	return newLocationWasFound;
}

void Board::throwGifts()
{
	Point giftLocation;
	int chance=(rand()%20)+1;//1-20
	//Bomb 0.05
	if(chance%20==0)//20
	{
		if(randomLocation(giftLocation))
		{
			setContent(giftLocation,'B');
			giftLocation.draw('B');
		}
	}
	//Arrow 0.1
	if(chance%10==0)//10,20
	{
		if(randomLocation(giftLocation))
		{
			setContent(giftLocation,'A');
			giftLocation.draw('A');
		}
	}
	//Food 0.2
	if(chance%5==0)//5,10,15,20
	{
		if(randomLocation(giftLocation))
		{
			setContent(giftLocation,'F');
			giftLocation.draw('F');
		}
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

void Board::Vladik()
{

}