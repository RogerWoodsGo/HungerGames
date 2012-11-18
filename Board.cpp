#include "Board.h"

void Board::readFile(char* fileName,char text[HEIGHT][WIDTH+1],int& numOfPlayersOnBoard,Point& scoreBoardPlace,PlayerList& pList)
{
	FILE* f;
	char ch;
	int nOPOB=0;
	bool OWasFound=false;
	Point sBP(0,0);
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
					if(nOPOB<NUMBEROFPLAYERS)
					{
						//text[i][j]='P';
						pList.Add(j,i);
						nOPOB++;
					}
					else text[i][j]=' ';
					break;
				case 'O':
					if(!OWasFound)
					{
						OWasFound=true;
						sBP.setPlace(i,j);
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
	numOfPlayersOnBoard=nOPOB;
	scoreBoardPlace=sBP;
}

void Board::printText(char text[HEIGHT][WIDTH+1],PlayerList& pList)
{
	for(int i=0;i<HEIGHT;i++)
	{
		cout << text[i] << endl;
	}
	pList.Print();
}