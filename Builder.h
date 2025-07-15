#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class RedBloon
{
public:

	//Constructor
	RedBloon();

	//Updating
	void redBloonUpdate(float& deltaTime);
	
	//Movement
	void moveBloon(float& deltaTime);

	//Drawing
	void drawRedBloon(sf::RenderWindow& window);



private:

	//Visuals
	sf::Texture m_Texture;							
	std::unique_ptr<sf::Sprite>(m_Sprite);

	//Entity values
	bool isBloonAlive;



};

class Tower
{
public:
	Tower();

	//Drawing
	void drawTower(sf::RenderWindow& window);

private:
	//Visuals
	sf::Texture m_Texture;
	std::unique_ptr<sf::Sprite>(m_Sprite);
};

//Systems

class Paused
{
public:
	Paused();
	void drawPause(sf::RenderWindow& window);

private:
	
	//Visuals
	sf::Texture m_Texture;
	std::unique_ptr<sf::Sprite>(m_Sprite);
};