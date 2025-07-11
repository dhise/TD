#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameSystems.h"

int main()
{

	//Window
	sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Robits");		// make x and y resolution into variables


	sf::Texture redbloon;
	redbloon.loadFromFile("graphics/redbloon.png");
	sf::Sprite redbloonsprite(redbloon);
	redbloonsprite.setPosition({ 200.f, 200.f });
	

	// game states
	enum class State {
		PAUSED,
		ACTIVE
	};
	State gameState;
	gameState = State::ACTIVE;





	while (window.isOpen())																	// only run game while window is open
	{
		while (const std::optional event = window.pollEvent())								// check all the windows events that were triggered since the last iteration of the loop
		{
			if (event->is<sf::Event::Closed>())	 window.close();							//if event is close requested then we close the window
			
		}
			

			
			
				
			
		if (gameState == State::ACTIVE)
		{
			window.clear(sf::Color::White);
			window.draw(redbloonsprite);
			
		}
		window.display();
	}


}