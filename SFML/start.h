#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 

class start
{
private:
	sf::Texture startButton;
	sf::Sprite startButtonImage;
	sf::Texture background;
	sf::Sprite backgroundImage;


public:

	bool ReactionStart = false;
	bool starting = true;
	void createbackground(std::string _fileName);
	void createStartButton1(std::string _fileName);
	void CheckStart(std::string target, std::string faketarget, std::string background);
	void drawStart(sf::RenderWindow& _win);
	void mouseMoved(sf::RenderWindow& _win);
	void mouseButtonPressed(sf::RenderWindow& _win);

};
