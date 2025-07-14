#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameSystems.h"

int main()
{
	
	//Go to Builder.cpp look for "here" make bloon move from left to right of screen

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


	//Testing																				TESTING REMOVE
	sf::Clock clock;
	sf::Time deltaTime;
	float deltaTimeAsSeconds;


	float testingThisnum;

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
		
		testingThisnum = deltaTimeAsSeconds * 200;
		std::cout << testingThisnum << std::endl;
		
		

		//Drawing
		if (gameState == State::ACTIVE)
		{	
			
			window.clear(sf::Color::White);
			redBloon.drawRedBloon(window);
		}
		else if (gameState == State::PAUSED)
		{	
			
			paused.drawPause(window);
		}
		window.display();
	}


}