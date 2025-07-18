#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameSystems.h"

int main()
{
	############
		############
		############
		############	//WORKING ON SETTING HEALTH TEXT POSITION ON BLOON Look for ##### in builder.h
		############
		############


	//Window	make x and y resolution into variables
	sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Robits");		


	//Game states
	enum class State {
		PAUSED,
		ACTIVE
	};
	State gameState;
	gameState = State::ACTIVE;

	//Creating Objects
	RedBloon redBloon;
	Paused paused;
	Tower tower;

	//Testing																				TESTING REMOVE
	sf::Clock clock;
	sf::Time deltaTime;
	float deltaTimeAsSeconds;

	
	sf::Font font("fonts/font.otf");
	sf::Text text(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Blue);
	std::stringstream testStream;
	testStream << "Hello " << std::endl;
	text.setString(testStream.str());
	text.setPosition({600.f, 600.f});




	// only run game while window is open
	while (window.isOpen())																	
	{
		while (const std::optional event = window.pollEvent())								// check all the windows events that were triggered since the last iteration of the loop
		{
			if (event->is<sf::Event::Closed>())	 window.close();							//if event is close requested then we close the window
		}
		
		//Pausing																			TEMP TEMP TEMP TEMP TEMP TEMP TEMP TEMP 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
		{
			gameState = State::PAUSED;
		}
		else
		{
			gameState = State::ACTIVE;
		}
		//End pause

		//Time
		deltaTime = clock.restart();
		deltaTimeAsSeconds = deltaTime.asSeconds();
		

		
		

		//Playing
		if (gameState == State::ACTIVE)
		{	
			redBloon.moveBloon(deltaTimeAsSeconds);

			window.clear(sf::Color::White);
			tower.drawTower(window);
			redBloon.drawRedBloon(window);
			window.draw(text);
		}
		else if (gameState == State::PAUSED)
		{	
			
			paused.drawPause(window);
		}
		window.display();
	}


}