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
	//m_Font.openFromFile("fonts/font.otf");
	

}

void PlayerResources::updatePlayerResources()
{
	m
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		m_BasicMetal += 1;
		std::cout << m_BasicMetal << std::endl;
	}

}

/*f::Text PlayerResources::returnText()
{
	
	sf::Text resourceText(m_Font);
	resourceText.setCharacterSize(24);
	resourceText.setFillColor(sf::Color::Black);
	resourceText.setPosition({ 400.0f, 200.0f });
	resourceText.setString(m_BasicMetalCount.str());
	return resourceText;
}*/

void PlayerResources::playerResourcesDraw(sf::RenderWindow& window)
{
	window.draw(returnText());

}