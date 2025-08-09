#include "sentry.h"



Sentry::Sentry()
{
	if (!m_Texture.loadFromFile("graphics/sentry.png"))
	{
		std::cerr << "failed to load sentry.png";
	}
	m_Sprite = std::make_unique<sf::Sprite>(m_Texture);

	m_Sprite->setPosition({ 600.0f, 600.0f });


}



void Sentry::drawSentry(sf::RenderWindow& window)
{

	window.draw(*m_Sprite);

}