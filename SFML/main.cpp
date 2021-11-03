#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 
#include "Reaction.h"

int main()
{
    // set the width and height so i can grab them vaules later
    int width = 1700;
    int height = 703;
    sf::RenderWindow window(sf::VideoMode(width, height), "reaction Game", sf::Style::Default);
    Reaction reaction;
    reaction.createButton("target1.png");
    reaction.createbackground("background.png");
    // creating the see for the radom number generater
    srand(time(NULL));
    while (window.isOpen())
    {
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
                reaction.mouseMoved(window);
            }
            break;
            case sf::Event::MouseButtonPressed:
            {
                reaction.mouseButtonPressed(window);

            }
            break;
            }
        }
        window.clear();
        reaction.drawgame(window);
        window.display();
    }
    return 0;
}