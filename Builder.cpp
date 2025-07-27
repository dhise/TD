#include "Builder.h"


//RedBloon
RedBloon::RedBloon()
{
	//Initializers
	m_Texture.loadFromFile("graphics/redbloon.png");			//64x64
	m_Sprite = std::make_unique<sf::Sprite>(m_Texture);
	
	isBloonAlive = true;

}





//RedBloon update funcion
void RedBloon::redBloonUpdate(float& deltaTime)												//Possibly create deltaTimeAsSeconds variable here
{
	//Updates
	m_Position = m_Sprite->getPosition();

}
	
//Movement

void RedBloon::moveBloon(float& deltaTime)
{
	//m_Sprite->setPosition({m_Sprite->getPosition().x + (200.0f * deltaTime), 0});

}

//Returns
sf::Vector2f RedBloon::returnBloonPosition()
{
	return m_Position;
}

//Drawing the redBloon
void RedBloon::drawRedBloon(sf::RenderWindow& window)
{
	if (isBloonAlive)
	{
		window.draw(*m_Sprite);
	}

}

//Tower
Tower::Tower()
{
	//Visuals
	m_Texture.loadFromFile("graphics/towerready.png");			//128x128
	m_Sprite = std::make_unique<sf::Sprite>(m_Texture);
	m_Sprite->setScale({.5f, .5f});
	m_Sprite->setPosition({ 700.f, 300.f });
	m_Sprite->setOrigin({ 32.0f, 32.0f });
	m_DartTexture.loadFromFile("graphics/dart.png");			//64x64
	m_DartSprite = std::make_unique<sf::Sprite>(m_DartTexture);	//sprites start by default 0,0 top left corner
	m_XPosition = m_Sprite->getPosition().x;
	m_YPosition = m_Sprite->getPosition().y;
	m_DartStartPosition = { m_XPosition - 16, m_YPosition - 64 };
	m_DartSprite->setPosition({m_DartStartPosition});
	attackKeyPressed = false;
	
	
	
	
}

//Updating
void Tower::towerUpdate()
{
	//Position tracking
	m_Position = m_Sprite->getPosition();
	m_DartStartPosition = { m_XPosition - 16, m_YPosition - 64 };	

	//Controls
	keyAttackPressed();

	
}

//Actions

void Tower::attack()
{
	

}

void Tower::keyAttackPressed()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
	{
		keyAttackPressed();
	}
	

}

//Drawing
void Tower::drawTower(sf::RenderWindow& window)
{
	window.draw(*m_Sprite);
	if (attackKeyPressed)							//only draws sprite while key is held
	{
		window.draw(*m_DartSprite);
	}
	
}

//Systems
Paused::Paused()
{
	m_Texture.loadFromFile("graphics/paused.png");
	m_Sprite = std::make_unique<sf::Sprite>(m_Texture);
	m_Sprite->setPosition({ 600.f, 600.f });
}

//Draw pause screen
void Paused::drawPause(sf::RenderWindow& window)
{
	window.draw(*m_Sprite);
}