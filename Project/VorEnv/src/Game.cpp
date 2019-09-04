#include "Game.h"

Game::Game() : 
m_window(sf::VideoMode(900, 900), "VorEnv", sf::Style::Default),
m_diagram()
{
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	timeSinceLastUpdate = clock.restart();

	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}
		}

		timeSinceLastUpdate += clock.restart();
		if (timeSinceLastUpdate > timePerFrame)
		{
			update(timeSinceLastUpdate.asMilliseconds());
			timeSinceLastUpdate = sf::Time::Zero;
		}

		render();
	}
}

void Game::update(sf::Int32 dt)
{
}

void Game::render()
{
	m_window.clear();
	m_diagram.render(m_window);
	m_window.display();
}
