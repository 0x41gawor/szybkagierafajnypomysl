#include "../include/Game.h"

Game::Game() :player{ nullptr }, enemies{ nullptr }, score{ nullptr }, cursor{ nullptr }, clock{ nullptr }
{
	window.create(sf::VideoMode::getDesktopMode(), "test&recognize", sf::Style::None);
	window.setMouseCursorVisible(false);
}

int Game::play()
{
	float dt{ 0.f };

	player = new Player();
	enemies = new EnemyManager();

	cursor = new HUD::Cursor();
	score = new HUD::Score();

	clock = new sf::Clock();


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::EventType::KeyPressed:
				if (sf::Keyboard::Key::Escape == event.key.code)
				{
					window.close();
					exit(0);
				}
				break;
			}
		}

		dt = clock->restart().asSeconds();

		//<  U P D A T E   S E C T I O N  >
		cursor->update(sf::Mouse::getPosition(window));
		player->update(dt, window);
		enemies->update(dt, window, *player);
		score->update(enemies->get__deadEnemies());
		//< / U P D A T E   S E C T I O N >

		if (player->get__isDead() == true)
		{
			break;
		}

		//<  D R A W   S E C T I O N  >
		window.clear();
		player->draw(window);
		enemies->draw(window);
		score->draw(window);
		cursor->draw(window);
		window.display();
		//< / D R A W   S E C T I O N >
	}

	delete player;
	delete enemies;
	delete cursor;
	delete score;
	delete clock;

	return enemies->get__deadEnemies();
}
