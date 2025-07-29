#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Tower
{
public:
	Tower();




private:
	//visuals
	sf::Texture m_Texture;
	std::unique_ptr<sf::Sprite>(m_Sprite);
	


};

