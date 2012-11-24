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
	}
	while(!newLocationWasFound)
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
	int chance=(rand()%22)+1;//1-22
	//Bomb 0.05
	if(chance%20==0)
	{
		if(randomLocation(giftLocation))
			setContent(giftLocation,'B')
	}
	//Arrow 0.1
	if(chance%10==1)
	{
		if(randomLocation(giftLocation))
			setContent(giftLocation,'A')
	}
	//Food 0.2
	if(chance%5==2)
	{
		if(randomLocation(giftLocation))
			setContent(giftLocation,'F')
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