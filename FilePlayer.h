#ifndef _FILEPLAYER_H_
#define _FILEPLAYER_H_

#include "Player.h"

class FilePlayer: public Player
{
	map<int,vector<char>*>* eventMap;
	FilePlayer(const FilePlayer&);
public:
	FilePlayer(int x,int y,char ch):Player(x,y,ch)
	{
		setDirection(Center);
		eventMap=new map<int,vector<char>*>;
		(*eventMap).empty();
	}
	map<int,vector<char>*>* getEventMap()const{return eventMap;}
	virtual void tryToMove(int playCounter);
	virtual void tryToShoot(ArrowList& aList,int playCounter);
	~FilePlayer();
};

#endif