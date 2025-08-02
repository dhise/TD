#include "gamesystems.h"



MousePointer::MousePointer()
{
	

}

void MousePointer::showMousePos(sf::RenderWindow& window)
{
	mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M))
	{
		std::cout << mousePos.x << " " << mousePos.y << std::endl;
	}

}

PlayerResources::PlayerResources()
{
	m_BasicMetal = 0;


}

void PlayerResources::updatePlayerResources()
{


}