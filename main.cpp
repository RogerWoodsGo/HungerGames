#include "Game.h"
#include <stdlib.h>
#include <time.h>

void main(int argc,char* argv[])
{
	Game g;
	srand((unsigned)(time(0)));
	g.play(argv[1]);
}