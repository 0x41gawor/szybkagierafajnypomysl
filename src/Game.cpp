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
	int deadEnemies = enemies->get__deadEnemies();
	delete enemies;
	delete cursor;
	delete score;
	delete clock;

	return deadEnemies;
}

void Game::show_score(int score)
{

	sf::Text textYourScore;
	sf::Text textScore;
	sf::Text textClickAnythingToPlay;
	sf::Font font;

	if (!font.loadFromFile("res/fonts/DS-DIGI.TTF")) std::cout << "Loading font gone wrong";

	textYourScore.setFont(font);
	textScore.setFont(font);
	textClickAnythingToPlay.setFont(font);

	textYourScore.setString("Your score:\n");
	textScore.setString(std::to_string(score));
	textClickAnythingToPlay.setString("\n Click any key to play again\n             [or esc to quit]");

	textYourScore.setCharacterSize(60);
	textScore.setCharacterSize(300);
	textClickAnythingToPlay.setCharacterSize(30);

	sf::FloatRect rect;

	rect = textYourScore.getGlobalBounds();
	textYourScore.setPosition(WIN_X / 2-rect.width/2, 220);
	rect = textScore.getGlobalBounds();
	textScore.setPosition(WIN_X / 2 - rect.width / 2, 280);
	rect = textClickAnythingToPlay.getGlobalBounds();
	textClickAnythingToPlay.setPosition(WIN_X / 2 - rect.width / 2, 600);


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
				return;
			}
			
		}

		window.draw(textYourScore);
		window.draw(textScore);
		window.draw(textClickAnythingToPlay);
		window.display();
	}
}
