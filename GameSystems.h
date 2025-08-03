#pragma once
#include <iostream>
#include "tower.h"
#include "reactor.h"


class MousePointer
{
public:
	MousePointer();

	//Debugging
	void showMousePos(sf::RenderWindow& window);


private:
	sf::Vector2f mousePos;

};

class PlayerResources
{
public:
	PlayerResources();
	sf::Text hudCurrentMetalCount(sf::Font& font);
	
	
	void updatePlayerResources();
	void playerResourcesDraw(sf::RenderWindow& window, sf::Font& font);
private:
	
	

	//Resources that will definitely change
	unsigned int m_CurrentMetalCount;

};