#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Tower													//@@This whole thing is currently for prototyping
{
public:
	Tower();

	void towerFire();

	//Draws
	void drawGatlingTower(sf::RenderWindow& window);

private:
	//visuals
	sf::Texture m_GatlingTurret;
	sf::Texture m_GatlingTurretFire1;
	sf::Texture m_GatlingTurretFire2;
	std::unique_ptr<sf::Sprite>(m_SpriteGatlingDefault);
	std::unique_ptr<sf::Sprite>(m_SpriteGatlingFire1);
	std::unique_ptr<sf::Sprite>(m_SpriteGatlingFire2);
	bool gatlingTowerFire;
	sf::Vector2f m_TowerPosition;

	//Time
	sf::Clock m_Clock;
	sf::Time m_Time;
	float deltaTime;
	float timeTotal;
};

