#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 

class Reaction
{
private:
	sf::Clock clock; // starts the clock
	sf::Texture Button;
	sf::Sprite ButtonImage;
	sf::Texture background;
	sf::Sprite backgroundImage;
	sf::Event Event;

	int width = 1700;
	int height = 703;

public:

	void createButton(std::string _fileName);
	void createbackground(std::string _fileName);
	void mouseMoved(sf::RenderWindow& _win);
	void mouseButtonPressed(sf::RenderWindow& _win);
	void drawgame(sf::RenderWindow& _win);
};
