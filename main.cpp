#include <iostream>
#include <SFML/Graphics.hpp>
#include "gamesystems.h"


//  @@ denotes more work needed
//	**********   denotes what I was working on last


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
	
	//System objects
	MousePointer mousePointer;
	PlayerResources playerResources;
	sf::Font font;
	font.openFromFile("fonts/font.otf");

	//Game objects
	State state;
	Reactor reactor;
	


	state = State::PLAYING;

	


	while (mainWindow.isOpen())
	{
		mousePointer.showMousePos(mainWindow);												//Press M to show coords current mouse pos

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
			playerResources.updatePlayerResources();

			//Draws
			reactor.drawReactor(mainWindow);
			playerResources.playerResourcesDraw(mainWindow, font);


		}
		mainWindow.display();
	}


}