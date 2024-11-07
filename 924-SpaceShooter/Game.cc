#include <iostream>

#include "game.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

constexpr float kCooldown_limit_ = 0.15f;

Game::Game()
{
	window_.create(sf::VideoMode(1280, 720), "Space Shooter");
}

void Game::Loop()
{

	window_.setMouseCursorVisible(false);

	float dt = 0.016f;

	while (window_.isOpen())
	{

		if (sf::Joystick::isButtonPressed(0, 0) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			player_missiles_.Spawn(starship_.GetPosition(), { 1500, 0 });
		}

		// what's the current position of the X and Y axes of joystick number 0?
		const float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		const float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
		if (x * x + y * y > 0)
			starship_.Move({ x / 100.0f , y / 100.0f }, dt);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			starship_.Move({ 0, -1 }, dt);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			starship_.Move({ 0, 1 }, dt);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			starship_.Move({ -1 , 0 }, dt);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			starship_.Move({ 1, 0 }, dt);


		sf::Event event;
		while (window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window_.close();

			if (event.type == sf::Event::MouseMoved)
			{
				starship_.SetPosition(sf::Vector2u(event.mouseMove.x, event.mouseMove.y));
			}

			// Sandbox test
			if (event.type == sf::Event::JoystickButtonReleased)
			{
				std::cout << "Button ID #" << event.joystickButton.button << '\n';
			}
			if (event.type == sf::Event::JoystickMoved)
			{
				std::cout << "Axis ID #" << event.joystickMove.axis << '\n';
			}

		}

		

		player_missiles_.Refresh(dt, window_.getSize());
		asteroids_.Refresh(dt, window_.getSize());

		enemy_missiles_.Refresh(dt, window_.getSize());
		enemy_manager_.Refresh(dt, window_.getSize(), enemy_missiles_);

		starship_.CheckCollisions(asteroids_.GetEntities());
		starship_.CheckCollisions(enemy_manager_.GetEntities());
		starship_.CheckCollisions(enemy_missiles_.GetEntities());

		player_missiles_.CheckCollisions(asteroids_.GetEntities());
		player_missiles_.CheckCollisions(enemy_manager_.GetEntities());

		window_.clear();
		window_.draw(player_missiles_);
		window_.draw(enemy_missiles_);
		window_.draw(asteroids_);
		window_.draw(enemy_manager_);
		window_.draw(starship_);
		window_.display();

		// At the end of the game loop
		dt = clock_.restart().asSeconds();

	}

	window_.setMouseCursorVisible(true);

}

