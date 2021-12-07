#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 
class Tetris
{
private:
    struct Point
    {
        int x, y;
    } a[4], b[4];


    int figures[7][4] = // This defines the shape of the different tetremominoes 
    {
        1,3,5,7, // I
        2,4,5,7, // Z
        3,5,4,6, // S
        3,5,4,7, // T
        2,3,5,7, // L
        3,5,7,6, // J
        2,3,4,5, // O
    };


public:
	void setup();
	bool check();
	void TetrisGame(sf::RenderWindow& Window);
};

