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
	

	//Drawing
	void drawRedBloon(sf::RenderWindow& window);



private:

	//Visuals
	sf::Texture m_Texture;							
	std::unique_ptr<sf::Sprite>(m_Sprite);

	//Entity values
	bool isBloonAlive;



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