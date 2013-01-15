#ifndef _GENERAL_H_
#define _GENERAL_H_

#include <iostream>
using namespace std;
#include <fstream>
#include <map>
#include <vector>

const int ESC=27;
const int WIDTH=79;
const int HEIGHT=24;
const int MAX_NUM_OF_COMPUTER_PLAYERS=2;
const int MAX_NUM_OF_HUMAN_PLAYERS=1;
const int MAX_NUM_OF_FILE_PLAYERS=3;
const int MIN_NUM_OF_PLAYERS_ON_BOARD=2;
const int MAX_NUM_OF_PLAYERS_ON_BOARD=3;
const char FOOD_GIFT='F';
const char ARROW_GIFT=(char)(24);
const char BOMB_GIFT='B';
const char PLAYER='P';
const char HUMAN_PLAYER=(char)(3);
const char ARROW='A';
const char REGULAR_ARROW=(char)(248);
const char PASSING_ARROW='+';
const char BOMBING_ARROW='*';
const char WALL=(char)(178);
const char BELL=(char)(7);
const int MIN_VALID_BOARD_PLACE_X=1;
const int MIN_VALID_BOARD_PLACE_Y=1;
const int MAX_VALID_BOARD_PLACE_X=18;
const int MAX_VALID_BOARD_PLACE_Y=68;
const int SCORE_BOARD_WIDTH=12;
const int SCORE_BOARD_HEIGHT=7;
const int NUM_OF_TRIES_TO_FIND_NEW_LOCATION=30;
const int DISTANCE_BETWEEN_ITEM_TO_PLAYER=2;
const int GIFT_CHANCE=20;
const double BOMB_CHANCE=0.05;
const double ARROW_CHANCE=0.1;
const double FOOD_CHANCE=0.2;
const int VECTOR_LIMIT=2;
const int LOW_POWER_PLAYER=200;
const int HIGH_POWER_PLAYER=10;
const int EQUAL_POWER_PLAYER=50;
const int NUM_OF_PLAYERS_WITH_MAX_SCORE=1;
const int ARROW_HIT_PLAYER=500;
const int PLAYER_ROUND_MOVE=2;
const int DIRECTION_OPTION=4;
const int SHOOTING_OPTION=3;
const int FOOD_BONUS=200;
const int ARROWS_BONUS=1;
const int BOMB_BONUS=-750;
const int CHANCE_TO_CHANGE_DIRECTION=7;
const int NUM_OF_FILE_TYPES=5;
const int NUM_OF_ROUNDS_TO_WAIT=3;
const int TIME_TO_REVIEW_FILES=4000;
const int SLEEP_TIME=50;

enum Direction{ 
	Center=0,
	Up=1,
	Right=2,
	Down=3,
	Left=4
};

enum ArrowType{
	None=0,
	Bombing=1,
	Passing=2,
	Regular=3
};

enum FileType{
	BoardFile=0,
	C1=1,
	C2=2,
	C3=3,
	E=4
};

enum PlayerType{
	Computer_Player=0,
	File_Player=1,
	Human_Player=2
};

#endif