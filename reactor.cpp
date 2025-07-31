#include "reactor.h"



Reactor::Reactor()
{
	if (!m_Texture.loadFromFile("graphics/reactoroff.png"))
	{
		std::cerr << "Failed to load reactoron.png";
	}
	m_Sprite = std::make_unique<sf::Sprite>(m_Texture);
	m_Sprite->setOrigin({ 128.0f / 2, 128.0f / 2 });
	m_Position = { 1920.0f / 2.0f, 900.0f };


	//Text
	m_Font.openFromFile("fonts/font.otf");					//*****************************
	test << "Test";											//**OKAY SO I WILL PROBABLY MAKE A FUNCTION THAT CONSTANTLY UPDATES THE string stream object  and then pull in the returnText function

	
	




}

sf::Text Reactor::returnText(sf::Font& font)			//*****************************
{
	
	sf::Text text(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Blue);
	text.setPosition({ 300.0f, 300.0f});
	text.setString(test.str());
	return text;

}

void Reactor::reactorUpdate()
{

	m_Sprite->setPosition(m_Position);

}


//Draw
void Reactor::drawReactor(sf::RenderWindow& window)
{
	window.draw(*m_Sprite);
	window.draw(returnText(m_Font));					//*****************************	

}