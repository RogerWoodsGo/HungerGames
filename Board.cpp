#include "Board.h"

void Board::readFile(char* fileName,PlayerList& pList)
{
	FILE* f;
	char ch,**text;
	bool OWasFound=false;
	text=new char*[HEIGHT];
	for(int i=0;i<HEIGHT;i++)
		text[i]=new char[WIDTH+1];
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
					text[i][j]=(char)178;
					break;
				case 'P':
					if(numOfPlayersOnBoard<NUMBEROFPLAYERS)
					{
						text[i][j]=' ';
						pList.Add(i,j);
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
		text[i][WIDTH]='\0';
	}
	fclose(f);
}

void Board::printText(PlayerList& pList)
{
	for(int i=0;i<HEIGHT;i++)
	{
		cout << text[i] << endl;
	}
	pList.Print();
}

char Board::getContent(int x, int y)
{
	return text[x][y];
}

Board::~Board()
{
	for(int i=0;i<HEIGHT;i++)
		delete text[i];
	delete []text;
}