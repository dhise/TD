#include "reactor.h"

Reactor::Reactor()
{
	if (!m_Texture.loadFromFile("graphics/reactoroff.png"))
	{
		std::cerr << "Failed to load reactoron.png";
	}
	m_Sprite = std::make_unique<sf::Sprite>(m_Texture);
	m_Sprite->setOrigin({ 128.0f / 2, 128.0f / 2 });

	//Text
	font.openFromFile("fonts/font.otf");


	//Location
	m_Position = { 1920.0f/2.0f, 900.0f };




}

void Reactor::reactorUpdate()
{

	m_Sprite->setPosition(m_Position);
}


//Draw
void Reactor::drawReactor(sf::RenderWindow& window)
{
	window.draw(*m_Sprite);

}