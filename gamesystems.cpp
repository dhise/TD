#include "gamesystems.h"



MousePointer::MousePointer()
{
	

}

//Debugging
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
	
	m_CurrentMetalCount = 0;
}

sf::Text PlayerResources::hudCurrentMetalCount(sf::Font& font)
{
	sf::Text currentMetalCount(font);
	currentMetalCount.setCharacterSize(24);
	currentMetalCount.setFillColor(sf::Color::Black);
	currentMetalCount.setPosition({ 400.0f, 200.0f });
	currentMetalCount.setString("Metal ");
	return currentMetalCount;

}

void PlayerResources::updatePlayerResources()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		m_CurrentMetalCount += 1;
	}
	std::cout << m_CurrentMetalCount << std::endl;
}

void PlayerResources::playerResourcesDraw(sf::RenderWindow& window, sf::Font& font)
{
	sf::Text displayText(font);
	window.draw(hudCurrentMetalCount(font));
	


}