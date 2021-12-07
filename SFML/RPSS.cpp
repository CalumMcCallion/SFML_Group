#include "RPS.h"
#include "RPSS.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 

void RPSS::RPSGame(sf::RenderWindow& window) {
    // set the width and height so i can grab them vaules later
    //int width = 1700;
    //int height = 703;
    //sf::RenderWindow window(sf::VideoMode(width, height), "RPS Game", sf::Style::Default);
    RPS rps;
    bool flag = false;
    rps.loadBackgroundMusic("music/backgroundmusic.wav");
    rps.PlayMusic();
    rps.createButtonR("images/Sword.png");
    rps.createButtonP("images/magician wand.png");
    rps.createButtonS("images/bow-arrow.png");
    rps.createbackground("images/Cave-map.png");
    // creating the see for the radom number generater
    srand(time(NULL));
    while (window.isOpen())
    {
        rps.displayTextL();
        rps.displayTextR();
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            switch (Event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
            {
                rps.mouseMoved(window);
            }
            break;
            case sf::Event::KeyPressed:
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    flag = true;
                }
            }
            break;
            case sf::Event::MouseButtonPressed:
            {
                rps.mouseButtonPressed(window);

            }
            break;
            }
        }
        window.clear();
        rps.drawgame(window);
        window.display();
        if (flag == true) {
            break;
        }
    }
    
}