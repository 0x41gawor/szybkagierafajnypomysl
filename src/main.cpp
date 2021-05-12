#include <SFML/Graphics.hpp>
#include "../include/constants.h"
#include "../include/Player.h"
#include "../include/Zombie.h"
#include "../include/Skeleton.h"
#include "../include/EnemyManager.h"
#include "../HUD/include/Score.h"
#include "../HUD/include/Cursor.h"

#include<iostream>

int main()
{
	srand(time(NULL));

	sf::RenderWindow window;
	window.create(sf::VideoMode::getDesktopMode(), "test&recognize", sf::Style::None);
	window.setMouseCursorVisible(false);

	Player player;
	EnemyManager enemies;

	HUD::Score score;
	HUD::Cursor cursor;


	sf::Clock clock;
	float dt{ 0.f };

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
					window.close();
				break;
			}
		}

		dt = clock.restart().asSeconds();

		//<  U P D A T E   S E C T I O N  >
		cursor.update(sf::Mouse::getPosition(window));
		player.update(dt, window);
		enemies.update(dt, window, player);
		score.update(enemies.get__deadEnemies());
		//< / U P D A T E   S E C T I O N >

		//<  D R A W   S E C T I O N  >
		window.clear();
		player.draw(window);
		enemies.draw(window);
		score.draw(window);
		cursor.draw(window);
		window.display();
		//< / D R A W   S E C T I O N >
	}
	
	std::cout<<"Score: "<<enemies.get__deadEnemies();
	getchar();

	return 0;

}