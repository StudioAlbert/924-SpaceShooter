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
                laser1_.setPosition(event.mouseButton.x, event.mouseButton.y);
            }

        }

        laser1_.Move();

        window_.clear();
        window_.draw(laser1_);
        window_.display();

    }
}

