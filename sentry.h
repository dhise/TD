#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>


class Sentry
{
public:
	Sentry();

	//Draws
	void drawSentry(sf::RenderWindow& window);

private:

	sf::Texture m_Texture;
	std::unique_ptr<sf::Sprite>(m_Sprite);

};