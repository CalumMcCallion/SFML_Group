#pragma once
#include <iostream>                                                     // std namespace
#include <SFML/Graphics.hpp>                                            // sf namespace 
#include <string>
#include "MoveBG.h"
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <windows.h> //Win32 import to use sleep function
#include <math.h>
#define _USE_MATH_DEFINES
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
using namespace std;
using namespace sf;

// Sprite speed (high values = high speed)
#define SPRITE_SPEED        10
class space {

private:
	sf::Time elapsed_time;
	sf::Clock r;


public:
	void spaceGame(sf::RenderWindow& Window);

};

