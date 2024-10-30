#include "Game.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

Game::Game()
{
   window_.create(sf::VideoMode(1280, 720), "Space Shooter");
}

void Game::Loop()
{
    while (window_.isOpen())
    {

    	sf::Event event;
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window_.close();

            if (event.type == sf::Event::MouseButtonReleased)
            {
                projectiles_.Spawn(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
            }

        }

        projectiles_.Refresh(dt_, window_.getSize());

        window_.clear();
    	window_.draw(projectiles_);
        window_.display();

        // At the end of the game loop
        dt_ = clock_.restart().asSeconds();

    }
}

