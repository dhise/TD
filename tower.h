#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Tower
{
public:
	Tower();




private:
	//visuals
	sf::Texture m_GatlingTurret;
	sf::Texture m_GatlingTurretFire1;
	sf::Texture m_GatlingTurretFire2;
	std::unique_ptr<sf::Sprite>(m_Sprite);
	


};

