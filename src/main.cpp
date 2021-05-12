#include <SFML/Graphics.hpp>
#include "../include/constants.h"
#include "../include/Player.h"
#include "../include/Zombie.h"
#include "../include/Skeleton.h"
#include "../include/EnemyManager.h"

#include<iostream>

int main()
{
	srand(time(NULL));

	sf::RenderWindow window;
	window.create(sf::VideoMode::getDesktopMode(), "test&recognize", sf::Style::None);

	Player player;
	EnemyManager enemies;

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
		player.update(dt, window);
		enemies.update(dt, window, player);
		//< / U P D A T E   S E C T I O N >

		//<  D R A W   S E C T I O N  >
		window.clear();
		player.draw(window);
		enemies.draw(window);
		window.display();
		//< / D R A W   S E C T I O N >
	}
	
	std::cout<<"Score: "<<enemies.get__score();
	getchar();

	return 0;

}