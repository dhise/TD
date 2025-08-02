#include <iostream>
#include <SFML/Graphics.hpp>
#include "gamesystems.h"


//Marked current work with ******   which is text stuff thanks

int main()
{
	
	unsigned int windowSizeX{ 1920 };
	unsigned int windowSizeY{ 1080 };

	
	sf::RenderWindow mainWindow(sf::VideoMode({ windowSizeX, windowSizeY }), "GAME");

	//Game states
	enum class State {
		PAUSED,
		PLAYING
	};
	
	//Game objects
	State state;
	Reactor reactor;

	state = State::PLAYING;

	


	while (mainWindow.isOpen())
	{
		while (const std::optional event = mainWindow.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				mainWindow.close();
			}
		}




		mainWindow.clear(sf::Color::White);
		if (state == State::PLAYING)
		{
			//Updates
			reactor.reactorUpdate();


			//Draws
			reactor.drawReactor(mainWindow);



		}
		mainWindow.display();
	}


}