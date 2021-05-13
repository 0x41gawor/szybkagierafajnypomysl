#pragma once

#include <SFML/Graphics.hpp>
#include "../include/constants.h"
#include "../include/Player.h"
#include "../include/Zombie.h"
#include "../include/Skeleton.h"
#include "../include/EnemyManager.h"
#include "../HUD/include/Score.h"
#include "../HUD/include/Cursor.h"


class Game
{
	sf::RenderWindow window;

	Player* player;
	EnemyManager* enemies;

	HUD::Score* score;
	HUD::Cursor* cursor;

	sf::Clock* clock;

  public:
	  Game();
	  int play();
	  void show_score(int score);
};

