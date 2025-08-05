#include "tower.h"


Tower::Tower()
{
	//visuals
	if (!m_GatlingTurret.loadFromFile("graphics/gatlingturret.png"))
	{
		std::cerr << "Failed to load sprite: gatlingturret";
	}
	
	
	if (!m_GatlingTurretFire1.loadFromFile("graphics/gatlingfire1.png"))
	{
		std::cerr << "Failed to load sprite: gatlingfire1";
	}

	if (!m_GatlingTurretFire2.loadFromFile("graphics/gatlingfire2.png"))
	{
		std::cerr << "Failed to load sprite: gatlingfire2";
	}
	m_SpriteGatlingDefault = std::make_unique<sf::Sprite>(m_GatlingTurret);
	m_SpriteGatlingFire1 = std::make_unique<sf::Sprite>(m_GatlingTurretFire1);
	m_SpriteGatlingFire2 = std::make_unique<sf::Sprite>(m_GatlingTurretFire2);
	gatlingTowerFire = false;

	m_TowerPosition = { 500.0f, 500.f };
	m_SpriteGatlingDefault->setPosition(m_TowerPosition);
	m_SpriteGatlingFire1->setPosition(m_TowerPosition);
	m_SpriteGatlingFire2->setPosition(m_TowerPosition);


	
	deltaTime = 0;
	timeTotal = 0;
}

void Tower::towerFire()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
	{
		gatlingTowerFire = true;
	}
	else gatlingTowerFire = false;
}
void Tower::drawGatlingTower(sf::RenderWindow& window)
{
	towerFire();
	
	static float deltaTime;
	static float deltaTimeTotal;
	m_Time = m_Clock.restart();
	deltaTime = m_Time.asSeconds();
	deltaTimeTotal += deltaTime;
	std::cout << deltaTimeTotal << std::endl;
	
	if (gatlingTowerFire == true)
	{
		if (rand() % 2 == 0)
		{
			window.draw(*m_SpriteGatlingFire1);
		}
		else
		{
			window.draw(*m_SpriteGatlingFire2);
		}
		
		
	}
	if(!gatlingTowerFire)
	{
		
		window.draw(*m_SpriteGatlingDefault);

	}
	

}