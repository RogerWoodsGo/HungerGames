#ifndef _GENERAL_H_
#define _GENERAL_H_

#include <iostream>
using namespace std;

const int WIDTH=79;
const int HEIGHT=24;
const int NUMBEROFPLAYERS=2;
const char FOOD_GIFT='F';
const char ARROW_GIFT='A';
const char BOMB_GIFT='B';
const char PLAYER='P';
const char ARROW=(char)(248);
const char WALL=(char)(178);
const int MIN_BOARD_HEIGHT_OR_WIDTH=0;
const int MAX_BOARD_HEIGHT=18;
const int MAX_BOARD_WIDTH=68;
const int SCORE_BOARD_WIDTH=12;
const int SCORE_BOARD_HEIGHT=7;
const int NUM_OF_TRIES_TO_FIND_NEW_LOCATION=30;
const int DISTANCE_BETWEEN_ITEM_TO_PLAYER=2;
const int BOMB_CHANCE=20;
const int ARROW_CHANCE=10;
const int FOOD_CHANCE=5;
const int LOW_POWER_PLAYER=200;
const int HIGH_POWER_PLAYER=10;
const int EQUAL_POWER_PLAYER=50;
const int NUM_OF_PLAYERS_WITH_MAX_SCORE=1;
const int ARROW_HIT_PLAYER=500;
const int PLAYER_ROUND_MOVE=2;
const int SLEEP_TIME=250;
const int DIRECTION_OPTION=4;
const int FOOD_BONUS=200;
const int ARROWS_BONUS=3;
const int BOMB_BONUS=750;
const int CHANCE_TO_CHANGE_DIRECTION=7;



enum Direction { 
	Up=0,
	Right=1,
	Down=2,
	Left=3
};

#endif