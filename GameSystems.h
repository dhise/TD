#pragma once
#include <iostream>
#include "tower.h"
#include "reactor.h"

class MousePointer
{
public:
	MousePointer();

	//Debugging
	void showMousePos(sf::RenderWindow& window);


private:
	sf::Vector2f mousePos;

};


//******** CURRENTLY ADDING REACTOR FUNCTIONS HERE FOR TESTING THESE WILL NEED TO BE RAN BY REACTOR CLASS 

class PlayerResources
{
public:
	PlayerResources();
	sf::Text hudCurrentMetalCount();
	
	
	void updatePlayerResources();
	void playerResourcesDraw(sf::RenderWindow& window);

	//Reactor
	void consoleCheck();
private:
	
	sf::Font m_Font;
	sf::Clock m_Clock;
	sf::Time m_Time;
	float m_GameSpeed;														//************************
	float m_DeltaTimeAsSeconds;
	float totalTime;

	//Resources that will definitely change
	unsigned int m_CurrentMetalCount;

	//Reactor variables
	bool m_ReactorOn;

};