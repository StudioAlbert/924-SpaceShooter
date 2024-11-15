#include <iostream>

#include "game.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

Game::Game()
{
	window_.create(sf::VideoMode(1280, 720), "Space Shooter");
	//window_.create(sf::VideoMode::getDesktopMode(), "Space Shooter", sf::Style::Fullscreen);

	font_.loadFromFile("Assets\\Fonts\\spaceboy\\SpaceBoy.ttf");
	score_.setFont(font_); 	// select the font
	score_.setCharacterSize(24); // set the character size in pixels, not points!
	score_.setFillColor(sf::Color::White);// set the color
	score_.setPosition(50, 50);

	lives_.setFont(font_); 	// select the font
	lives_.setCharacterSize(24); // set the character size in pixels, not points!
	lives_.setFillColor(sf::Color::White);// set the color
	lives_.setPosition(window_.getSize().x - 200, 50);

	score_.setString("Score : ");// set the string to display
	lives_.setString("Lives : ");// set the string to display

}

void Game::Loop()
{

	window_.setMouseCursorVisible(false);

	double dt = 0.016f;
	int score_points = 0;

	while (window_.isOpen())
	{

		if (sf::Joystick::isButtonPressed(0, 0) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if(starship_.GetHp() > 0 && starship_.IsShootReady())
			{
				player_missiles_.Spawn(starship_.GetPosition(), { 1500, 0 });
				starship_.ShootConfirm();
			}
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
				starship_.SetPosition(sf::Vector2u(event.mouseMove.x, event.mouseMove.y));

			// Sandbox test
			if (event.type == sf::Event::JoystickButtonReleased)
				std::cout << "Button ID #" << event.joystickButton.button << '\n';

			if (event.type == sf::Event::JoystickMoved)
				std::cout << "Axis ID #" << event.joystickMove.axis << '\n';

			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Escape)
				{
					// Fullscreen <=> not fullscreen
					window_.close();
				}
			}

		}

		if(starship_.GetHp() > 0)
		{
			starship_.Refresh(dt);
		}
		asteroids_.Refresh(dt, window_.getSize());
		player_missiles_.Refresh(dt, window_.getSize());
		enemy_missiles_.Refresh(dt, window_.getSize());
		enemy_manager_.Refresh(dt, window_.getSize(), enemy_missiles_);

		if(starship_.GetHp() > 0)
		{
			starship_.CheckCollisions(asteroids_.GetEntities());
			starship_.CheckCollisions(enemy_manager_.GetEntities());
			starship_.CheckCollisions(enemy_missiles_.GetEntities());
		}

		score_points += player_missiles_.CheckCollisions(asteroids_.GetEntities());
		score_points += 5 * player_missiles_.CheckCollisions(enemy_manager_.GetEntities());
		
		score_.setString("Score : " + std::to_string(score_points));
		lives_.setString("Lives : " + std::to_string(starship_.GetHp()));

		window_.clear();
		window_.draw(player_missiles_);
		window_.draw(enemy_missiles_);
		window_.draw(asteroids_);
		window_.draw(enemy_manager_);

		if(starship_.GetHp() > 0)
		{
			window_.draw(starship_);
		}else
		{
			// GAME OVER
			// Music de game over
			// Texte de game over
			// etc......
		}

		window_.draw(score_);
		window_.draw(lives_);
		window_.display();

		// At the end of the game loop
		dt = clock_.restart().asSeconds();
		//std::cout << "dt ? : " << dt << std::endl;

	}

	window_.setMouseCursorVisible(true);

}

