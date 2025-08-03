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
	
	void updatePlayerResources();
	sf::Text returnText();

	void playerResourcesDraw(sf::RenderWindow& window);
private:
	
	sf::Font m_Font;
	std::stringstream m_BasicMetalCount;
	int m_BasicMetalQuantity;

	//Resources that will definitely change
	unsigned int m_BasicMetal;

};