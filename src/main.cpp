#include <iostream>
#include <time.h>

#include "../include/Game.h"


int main()
{
	srand(time(NULL));

	Game game;
	for (;;)
	{
		int score = game.play();
		game.show_score(score);
	}

	return 0;
}