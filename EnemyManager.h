#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Zombie.h"
#include "Skeleton.h"
#include "Bullet.h"
#include "Player.h"
class EnemyManager
{
	std::vector<Zombie> zombies;															//vector of zombies
	std::vector<Skeleton> skeletons;														//vector of skeletons

	float freqTimeZom;																		//how often do Zombies spawn
	float freqTimeSke;																		//how often do Skeletons spawn
	float timeSinceLastSpawnZom;															//auxiliary variable
	float timeSinceLastSpawnSke;															//auxiliary variable

public:
	EnemyManager(float freqTimeZom = ZOMBIE_FREQ, float freqTimeSke = SKELETON_FREQ);
	void draw(sf::RenderWindow& w);
	void update(float dt, sf::RenderWindow& w, Player& player);

	sf::Vector2f update__generate_position();

};

