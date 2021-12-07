#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 

class RPS
{
private:
	sf::Clock clock; // starts the clock
	sf::Texture Button;
	sf::Sprite ButtonImage;
	sf::Texture background;
	sf::Sprite backgroundImage;
	sf::Event Event;
	sf::Texture ButtonR;
	sf::Sprite ButtonImageR;
	sf::Texture ButtonP;
	sf::Sprite ButtonImageP;
	sf::Texture ButtonS;
	sf::Sprite ButtonImageS;
	sf::Music music;
	sf::Clock TimerS;
	sf::Text textL;
	sf::Text textR;
	sf::Text gameOver;
	sf::Font font;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	int width = 1700;
	int height = 703;

	// Variable to determin when does the game over

	int life = 3;
	int eLife = 3;


public:

	void createButton(std::string _fileName);
	void createButtonP(std::string _fileName);
	void createButtonS(std::string _fileName);
	void createButtonR(std::string _fileName);
	void createbackground(std::string _fileName);
	void soundDelay(int ms);
	void loadBackgroundMusic(std::string music);
	void PlayMusic();
	void mouseMoved(sf::RenderWindow& _win);
	void mouseButtonPressed(sf::RenderWindow& _win);
	void drawgame(sf::RenderWindow& _win);
	void displayTextL();
	void displayTextR();
	void gameover();
};
