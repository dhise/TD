#include "Builder.h"


//RedBloon
RedBloon::RedBloon()
{
	m_Texture.loadFromFile("graphics/redbloon.png");
	m_Sprite = std::make_unique<sf::Sprite>(m_Texture);
	isBloonAlive = true;
	m_Sprite->setPosition({ 300.f, 300.f });
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
void RedBloon::redBloonUpdate(float& deltaTime)
{
	//HERE HERE HERE HERE HERE HERE HERE HERE HERE HERE HERE HERE HERE HERE HERE HERE HERE HERE HERE HERE HERE 
}
	
//Movement

void RedBloon::moveBloon(float& deltaTime)
{
	m_Sprite->setPosition({m_Sprite->getPosition().x + (200.0f * deltaTime), 0});

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