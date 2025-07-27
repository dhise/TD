#include <iostream>
#include <SFML/Graphics.hpp>
#include "gamesystems.h"

int main()
{
	

	sf::RenderWindow mainWindow(sf::VideoMode({ 1920, 1080 }), "GAME");



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