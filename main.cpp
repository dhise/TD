#include <iostream>
#include <SFML/Graphics.hpp>
#include "gamesystems.h"


//  @@ denotes more work needed
//	**********   denotes what I was working on last

//Made the tower sprite change based on firing and made the muzzle flash randomly change   i will need to rethink sprites though as they will turn to focus enemies
//I need to figure out a global timer of some sorts so that everything operates off the same ticks of time. So a tick rate that is universal. 


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
	

	//Game objects
	State state;
	Reactor reactor;
	Tower tower;


	state = State::PLAYING;
	srand((int)time(NULL));
	


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



		//Draws
		mainWindow.clear(sf::Color::White);
		if (state == State::PLAYING)
		{
			//Updates
			reactor.reactorUpdate();
			playerResources.updatePlayerResources();

			//Draws
			reactor.drawReactor(mainWindow);
			playerResources.playerResourcesDraw(mainWindow);
			tower.drawGatlingTower(mainWindow);

		}
		mainWindow.display();
	}


}