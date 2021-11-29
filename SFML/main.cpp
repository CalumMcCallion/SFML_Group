#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 
#include "Reaction.h"
#include "start.h"
//credit: Mr Smith - Americana  FMA
int x = sf::VideoMode::getDesktopMode().width;
int y = sf::VideoMode::getDesktopMode().height;


int main()
{
    std::cout << "screen width: " << x << std::endl;
    std::cout << "Screen height " << y << std::endl;
    // set the width and height so i can grab them vaules later
    int width = 1700;
    int height = 703;

    sf::RenderWindow window(sf::VideoMode(x, y), "reaction Game", sf::Style::Default);
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
            // loads reaction game's assets
            reaction.startGame();
            start.ReactionStart == false;
            starting = false;
        }
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            reaction.Moved(window);
            switch (Event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
            {
                // shows the user highlighted button
                start.mouseMoved(window);

                //show the user highlighted target
                reaction.mouseMoved(window);
            }
            break;
            case sf::Event::MouseButtonPressed:
            {
                // allows user to play game through making starting == true
                start.mouseButtonPressed(window);

                // allows user to hit target and adds points ort takes them away
                reaction.mouseButtonPressed(window);

                // if (reaction.REmouseButtonPressed(window)== true) {
               //      goto start;
               //  }


            }
            break;
            }



        }



        window.clear();
        // draws start menu
        start.drawStart(window);
        // allows reaction game to draw
        reaction.drawgame(window);
        window.display();

    }
    return 0;
}