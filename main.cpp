#include "Game.h"
#include <time.h>

void main(int argc,char* argv[])
{
	Game g;
	srand((unsigned)(time(0)));
	g.run(argv[1]);
}