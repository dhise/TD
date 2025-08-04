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
	addingOne = true;
	m_CurrentPower = 0;
	testTime = testClock.restart();
	
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

sf::Text PlayerResources::hudCurrentPowerCount()
{
	sf::Text currentPowerCount(m_Font);
	std::stringstream powerDisplay;
	powerDisplay << "Power " << static_cast<int>(m_CurrentPower);
	currentPowerCount.setCharacterSize(24);
	currentPowerCount.setFillColor(sf::Color::Blue);
	currentPowerCount.setPosition({ 250.0f, 50.0f });
	currentPowerCount.setString(powerDisplay.str());
	return currentPowerCount;

}

void PlayerResources::powerGeneration()															//@@This works currently but it's bloated and weird
{
	testTime = testClock.restart();
	static float deltaTimeAsSeconds = 0;
	deltaTimeAsSeconds += testTime.asSeconds();
	static float powerGenerationRate = 0.0f;
	std::cout << powerGenerationRate << std::endl;

	if (static_cast<int>(deltaTimeAsSeconds) - powerGenerationRate > 3.0f)
	{
		m_CurrentPower += 1;
		powerGenerationRate = deltaTimeAsSeconds;
	}
	
}

void PlayerResources::updatePlayerResources()											//@@Need to figure out the actual way to store these variables
{
	m_Time = m_Clock.restart();
	
	m_DeltaTimeAsSeconds = m_Time.asSeconds(); //Global multiplyer for speed											
	totalTime += m_Time.asSeconds();	
	
	//Reactor
	consoleCheck();
	powerGeneration();
}

void PlayerResources::playerResourcesDraw(sf::RenderWindow& window)
{

	window.draw(hudCurrentMetalCount());
	window.draw(hudCurrentPowerCount());
}


