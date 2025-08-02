#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


w

class Reactor
{
public:
	Reactor();

	void reactorUpdate();

	sf::Text returnText(sf::Font& font);							//*****************************

	//Draw
	void drawReactor(sf::RenderWindow& window);
private:
	//Sprite
	sf::Texture m_Texture;
	std::unique_ptr<sf::Sprite> m_Sprite;

	//Member variables
	sf::Vector2f m_Position;
	
	//Text
	sf::Font m_Font;												//*****************************
	


	std::stringstream test;											//*****************************



};