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
	sf::Texture fakeButton;
	sf::Sprite fakeButtonImage;
	sf::Texture background;
	sf::Sprite backgroundImage;
	//sf::Texture REButton;
	//sf::Sprite REButtonImage;
	
	sf::SoundBuffer buffer1;
	sf::SoundBuffer buffer2;
	sf::Sound sound1;
	sf::Sound sound2;
	sf::Music music;

	sf::Event Event;
	bool flag = true;
	int width = 1700;
	int height = 703;


public:

	int count = 0;
	int points = 0;
	sf::Clock clock1;
	sf::Time elapsed2;
	sf::Text text;
	sf::Font font;
	sf::Clock TimerS;

	void createButton(std::string _fileName);
	void createFakeButton(std::string _fileName);
	void createbackground(std::string _fileName);
	//void createStartButton1(std::string _fileName);
	void soundDelay(int ms);
	void LoadSound(std::string gunshot);
	void loadBackgroundMusic(std::string music);
	void PlayMusic();
	void PlaySound();
	void startGame();
	void mouseMoved(sf::RenderWindow& _win);
	void mouseButtonPressed(sf::RenderWindow& _win);
	void drawgame(sf::RenderWindow& _win);
	void creacteEndText(float time);
	//bool REmouseButtonPressed(sf::RenderWindow& _win);

};
