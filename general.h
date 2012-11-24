#ifndef _GENERAL_H_
#define _GENERAL_H_

#include <iostream>
using namespace std;

const int WIDTH=79;
const int HEIGHT=24;
const int NUMBEROFPLAYERS=2;
const char FOOD='F';
const char ARROW='A';
const char BOMB='B';
const char WALL=(char)(178);


enum Direction { 
	Up=0,
	Right=1,
	Down=2,
	Left=3
};

#endif