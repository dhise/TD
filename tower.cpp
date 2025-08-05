#include "tower.h"


Tower::Tower()
{
	//visuals
	if (!m_GatlingTurret.loadFromFile("graphics/gatlingturret.png"))
	{
		std::cerr << "Failed to load tower graphic";
	}
	m_Sprite = std::make_unique<sf::Sprite>(m_GatlingTurret);
	
	if (!m_GatlingTurretFire1.loadFromFile("graphics/gatlingfire1"))
	{
		std::cerr << "Failed to load gatlingturretfire1";
	}

	if (!m_GatlingTurretFire2.loadFromFile("graphics/gatlingfire2"))
	{
		std::cerr << "Failed to load gatlingturretfire2";
	}




}