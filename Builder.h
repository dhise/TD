#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class RedBloon
{
public:

	
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
	sf::Vector2f m_Position;
	

	//Text
	sf::Vector2f m_HealthTextLocation; 
	


	

};

class Tower
{
public:
	Tower();

	//Updating
	void towerUpdate();
	
	

	//Action
	void attack();
	void keyAttackPressed();

	//Drawing
	void drawTower(sf::RenderWindow& window);
	void drawDart();		//using a function in draw function
	

private:
	//Visuals
	sf::Texture m_Texture;
	std::unique_ptr<sf::Sprite>(m_Sprite);
	sf::Texture m_DartTexture;
	std::unique_ptr<sf::Sprite>(m_DartSprite);

	//Entity values
	sf::Vector2f m_Position;
	float m_XPosition;					//to track x y of position
	float m_YPosition;

	//Attack variables
	sf::Vector2f m_DartPosition;
	sf::Vector2f m_DartStartPosition;
	sf::Vector2f m_ProjStart;					//used for constantly updating the variable of where projectiles from this tower should start
	bool attackKeyPressed;
	



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