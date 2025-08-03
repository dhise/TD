#include "gamesystems.h"


//Mouse pointer
MousePointer::MousePointer()
{
	

}

//Debugging
void MousePointer::showMousePos(sf::RenderWindow& window)
{
	mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M))
	{
		std::cout << mousePos.x << " " << mousePos.y << std::endl;
	}

}


//Player resources
PlayerResources::PlayerResources()
{
	if (!m_Font.openFromFile("fonts/font.otf"))
	{
		std::cerr << "Error loading font " << std::endl;
	}
	m_CurrentMetalCount = 0;
	m_GameSpeed = 200.0f;
	totalTime = 0.0f;
	//Reactor stuff
	m_ReactorOn = false;
	m_DeltaTimeAsSeconds = 0;
}

sf::Text PlayerResources::hudCurrentMetalCount()									//@@This will need to be cleaned up. Make a function that takes a text and then adds all the variables to it. 
{
	sf::Text currentMetalCount(m_Font);
	std::stringstream numberDisplay;
	numberDisplay << "Metal " << static_cast<int>(m_CurrentMetalCount);
	currentMetalCount.setCharacterSize(24);
	currentMetalCount.setFillColor(sf::Color::Black);
	currentMetalCount.setPosition({ 100.0f, 50.0f });
	currentMetalCount.setString(numberDisplay.str());
	return currentMetalCount;

}

void PlayerResources::consoleCheck()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T))
	{
		if (m_ReactorOn)
		{
			std::cout << "Reactor online " << std::endl;
		}
		if (!m_ReactorOn)
		{
			std::cout << "Reactor offline " << std::endl;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
	{
		if (m_ReactorOn)
		{
			m_ReactorOn = false;
			std::cout << "Reactor shut down... " << std::endl;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
	{
		if (!m_ReactorOn)
		{
			m_ReactorOn = true;
			std::cout << "Reactor starting... " << std::endl;
		}
	}
	
}

void PlayerResources::updatePlayerResources()											//*******Currently working here. Go over this to see what you can use as a timer for events
{
	m_Time = m_Clock.restart();
	m_DeltaTimeAsSeconds = m_Time.asSeconds();
	totalTime += m_Time.asSeconds();
	std::cout << totalTime << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		m_CurrentMetalCount += 1;
	}
	
	//Reactor
	consoleCheck();
}

void PlayerResources::playerResourcesDraw(sf::RenderWindow& window)
{

	window.draw(hudCurrentMetalCount());
	


}