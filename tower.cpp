#include "tower.h"


Tower::Tower()
{
	//visuals
	if (!m_Texture.loadFromFile("graphics/tower.png"))
	{
		std::cerr << "Failed to load tower graphic";
	}
	m_Sprite = std::make_unique<sf::Sprite>(m_Texture);
	




}