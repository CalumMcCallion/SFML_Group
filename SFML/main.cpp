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
    reaction.createFakeButton("faketarget.png");
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
            if (reaction.count == 20) {
                reaction.elapsed2 = reaction.clock1.getElapsedTime();
                const float time = reaction.elapsed2.asSeconds();
                reaction.text.setFont(reaction.font);   reaction.text.setCharacterSize(25);  reaction.text.setFillColor(sf::Color::Black); reaction.text.setStyle(sf::Text::Bold | sf::Text::Underlined);
                reaction.text.setString(std::to_string(reaction.points) + "\n" + std::to_string(time));
                reaction.text.setPosition(850, 350);
            }
            if (!reaction.font.loadFromFile("arial.ttf"))
            {
                // error...
            }
            
            
        }

        

        window.clear();
        reaction.drawgame(window);
        window.draw(reaction.text);
        window.display();

    }
    return 0;
}