#include "Builder.h"


//RedBloon
RedBloon::RedBloon()
{
	//Initializers
	m_Texture.loadFromFile("graphics/redbloon.png");
	m_Sprite = std::make_unique<sf::Sprite>(m_Texture);
	isBloonAlive = true;
	sf::Font m_Font;
	sf::Text m_Text(m_Font);
	
	
	//Values
	m_Health = 10;


	//Text
	m_Font.openFromFile("fonts/font.otf");
	m_Text.setFont(m_Font);
	m_Text.setCharacterSize(24.f);
	m_Text.setFillColor(sf::Color::Blue);

	//Strings
	std::stringstream healthStream;
	healthStream << m_Health;
	m_Text.setString(healthStream.str());

}

//Drawing the redBloon
void RedBloon::drawRedBloon(sf::RenderWindow& window)
{
	if (isBloonAlive)
	{
		window.draw(*m_Sprite);
	}
	
}

//redBloon update funcion
void RedBloon::redBloonUpdate(float& deltaTime)												//Possibly create deltaTimeAsSeconds variable here
{
	//Updates
	m_Position = m_Sprite->getPosition();

}
	
//Movement

void RedBloon::moveBloon(float& deltaTime)
{
	m_Sprite->setPosition({m_Sprite->getPosition().x + (200.0f * deltaTime), 0});

}

//Tower
Tower::Tower()
{
	//Visuals
	m_Texture.loadFromFile("graphics/towerready.png");
	m_Sprite = std::make_unique<sf::Sprite>(m_Texture);
	m_Sprite->setScale({.5f, .5f});
	m_Sprite->setPosition({ 700.f, 300.f });

	
}

//Drawing
void Tower::drawTower(sf::RenderWindow& window)
{
	window.draw(*m_Sprite);
}

//Systems
Paused::Paused()
{
	m_Texture.loadFromFile("graphics/paused.png");
	m_Sprite = std::make_unique<sf::Sprite>(m_Texture);
	m_Sprite->setPosition({ 600.f, 600.f });
}

//Draw pause screen
void Paused::drawPause(sf::RenderWindow& window)
{
	window.draw(*m_Sprite);
}