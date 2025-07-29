#include <iostream>
#include <SFML/Graphics.hpp>
#include "gamesystems.h"

int main()
{
	
	unsigned int windowSizeX{ 1920 };
	unsigned int windowSizeY{ 1080 };

	
	sf::RenderWindow mainWindow(sf::VideoMode({ windowSizeX, windowSizeY }), "GAME");



	while (mainWindow.isOpen())
	{
		while (const std::optional event = mainWindow.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				mainWindow.close();
			}
		}




		mainWindow.display();
	}


}