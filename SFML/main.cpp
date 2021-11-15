#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 
#include "Reaction.h"
#include "start.h"

int main()
{
    // set the width and height so i can grab them vaules later
    int width = 1700;
    int height = 703;

    sf::RenderWindow window(sf::VideoMode(width, height), "reaction Game", sf::Style::Default);
    Reaction reaction;
    start start;
    bool starting = true;
    bool other = true;
    
    start.createStartButton1("title.PNG");
    // creating the see for the radom number generater
    srand(time(NULL));
    while (window.isOpen())
    {
        
            
            
            
        
        if (start.ReactionStart == true && starting == true) {
          /*  reaction.createButton("target1.png");
            reaction.createbackground("background.png");
            reaction.createFakeButton("faketarget.png");  
            reaction.loadBackgroundMusic("Mr Smith - Americana.wav");
            reaction.PlayMusic();
            reaction.LoadSound("gunshot.wav");*/
            reaction.startGame();
            start.ReactionStart == false;
            starting = false;
        }
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

                start.mouseButtonPressed(window);

                
                   reaction.mouseButtonPressed(window);
                
                

            }
            break;
            }

            

        }



        window.clear();
        start.drawStart(window);
        reaction.drawgame(window);
        window.display();

    }
    return 0;
}