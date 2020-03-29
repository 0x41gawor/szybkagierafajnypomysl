#include "EnemyManager.h"

EnemyManager::EnemyManager(float freqTimeZom, float freqTimeSke) :freqTimeZom{ freqTimeZom }, freqTimeSke{ freqTimeSke }, timeSinceLastSpawnZom{ 0.f }, timeSinceLastSpawnSke{ 0.f }
{
	;;
}

void EnemyManager::draw(sf::RenderWindow& w)
{
	for (int i = 0; i < (int)zombies.size(); i++)
		zombies[i].draw(w);
	for (int i = 0; i < (int)skeletons.size(); i++)
		skeletons[i].draw(w);
}

void EnemyManager::update(float dt, sf::RenderWindow& w, Player& player)
{
	std::vector<Bullet>& playerGun = *player.gun_share_bullets();

	timeSinceLastSpawnZom += dt;
	timeSinceLastSpawnSke += dt;
	//zombies spawning
	if (timeSinceLastSpawnZom > freqTimeZom)
	{
		int sel = rand() & 3;
		switch (sel)
		{
		case 0: case 1: case 2:
			zombies.emplace_back(update__generate_position(), 30.f, 80.f, ZOMBIE_MS, ZOMBIE_LAVIE, sf::Color(ZOMBIE_COLOR));
			break;
		case 3: 
			zombies.emplace_back(update__generate_position(), 25.f, 70.f, ZOMBIE2_MS, ZOMBIE2_LAVIE, sf::Color(ZOMBIE2_COLOR));
			break;
		}
		timeSinceLastSpawnZom = 0.f;
	}
	//skeletons spawning
	if (timeSinceLastSpawnSke > freqTimeSke)
	{
		int sel = rand() & 3;
		switch (sel)
		{
		case 0: case 1: case 2:
			skeletons.emplace_back(update__generate_position(), 30.f, 80.f, SKELETON_MS, SKELETON_LAVIE, sf::Color(SKELETON_COLOR), 4, sf::Color(S_GUN_COLOR), S_GUN_VELOCITY, S_GUN_DAMAGE, S_GUN_AS);
			break;
		case 3:
			skeletons.emplace_back(update__generate_position(), 35.f, 90.f, SKELETON2_MS, SKELETON2_LAVIE, sf::Color(SKELETON2_COLOR), 8, sf::Color(S2_GUN_COLOR), S2_GUN_VELOCITY, S2_GUN_DAMAGE, S2_GUN_AS);
			break;
		}
		timeSinceLastSpawnSke = 0.f;
	}
	//update and erase dead zombies xd
	for (int i = 0; i < (int)zombies.size(); i++)
	{
		zombies[i].update(dt, w, player.get__position());
		if (zombies[i].get__dead())
		{
			zombies.erase(zombies.begin() + i);
		}
	}
	//update and erasing dead skeletons xdxd
	for (int i = 0; i < (int)skeletons.size(); i++)
	{
		skeletons[i].update(dt, w, player.get__position());
		if (skeletons[i].get__dead())
		{
			skeletons.erase(skeletons.begin() + i);
		}
	}
	//zombies collision
	for (int i = 0; i < (int)zombies.size(); i++)
	{
		if (zombies[i].get__Global_Bounds().intersects(player.get__Global_Bounds()))	//with player
			player.take_damage(ZOMBIE_DMG);

		for (int j = 0; j < (int)playerGun.size(); j++)
		{
			if (zombies[i].get__Global_Bounds().contains(playerGun[j].get__position()))	//with player's bullet
			{
				zombies[i].take_damage(player.get__gun_damage());
				playerGun[j].set__dead(true);
			}
		}
	}
	//skeletons collisions
	for (int i = 0; i < (int)skeletons.size(); i++)
	{
		for (int j = 0; j < (int)playerGun.size(); j++)
		{
			if (skeletons[i].get__Global_Bounds().contains(playerGun[j].get__position())) //with player's bullet
			{
				skeletons[i].take_damage(player.get__gun_damage());
				playerGun[j].set__dead(true);
			}
		}
	}
	//skeletons collisions v2
	for (int i = 0; i < (int)skeletons.size(); i++)
	{
		std::vector<Bullet>& skeletonGun = *skeletons[i].gun_share_bullets();
		for (int j = 0; j < (int)skeletons[i].gun_share_bullets()->size(); j++)
		{
			if (player.get__Global_Bounds().contains(skeletonGun[j].get__position())) //their bullets with player
			{
				player.take_damage(skeletons[i].get__gun_damage());
				skeletonGun[j].set__dead(true);
			}
		}
	}
}

sf::Vector2f EnemyManager::update__generate_position()
{
	float x{ 0.f }, y{ 0.f };
	int sel = rand() & 3;
	switch (sel)
	{
	case 0:
	{
		x = 0.f; y = (float)rand() / RAND_MAX * WIN_Y;
		break;
	}
	case 1:
	{
		x = (float)rand() / RAND_MAX * WIN_X; y = 0.f;
		break;
	}
	case 2:
	{
		x = WIN_X; y = (float)rand() / RAND_MAX * WIN_Y;
		break;
	}
	case 3:
	{
		x = (float)rand() / RAND_MAX * WIN_X; y = WIN_Y;
		break;
	}
	}

	return sf::Vector2f(x, y);
}


