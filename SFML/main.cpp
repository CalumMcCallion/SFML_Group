/*
* An SFML application - Darryl Charles
* SFML Documentation https://www.sfml-dev.org/documentation/2.5.1/
* SFML Shapes Tutorials https://www.sfml-dev.org/tutorials/2.5/graphics-shape.php
* SGML Graphics tutorial https://gamefromscratch.com/sfml-c-tutorial-basic-graphics/
*/
#include <iostream>                                                     // std namespace
#include <SFML/Graphics.hpp>                                            // sf namespace 
#include "graphPoints.h"

int main()
{
#pragma region Window Creation
    sf::RenderWindow window(sf::VideoMode(350, 100), "Plot Points!", sf::Style::Default, sf::ContextSettings(24));   // render a Window
    window.setVerticalSyncEnabled(true);
    std::vector<sf::Text> numTxt;
    sf::Text text;
    sf::Font font;
   

    sf::Vector2u winSize = window.getSize();
    
    
#pragma endregion
    graphPoints graphPts;                                               // create an instance of my point plotting class
   
    //loads the file
    graphPts.loadPoints("HeartRate.csv");
    while (window.isOpen())                                             // This is the Windows application loop - infinite loop until closed
    {

#pragma region Check for Exit
        sf::Event event;                                                // Windows is event driven - so check for events
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();

        }
        window.clear(sf::Color(255, 0, 0));
        //loads the font
        if (!font.loadFromFile("arial.ttf"))
        {
            // error...
        }
        int num = 50;
        int pos = 69;
        // time labels assigned to vector
        for (int i = 0; i < 5; i++) {
            numTxt.push_back(text);
            text.setFont(font);   text.setCharacterSize(9);  text.setFillColor(sf::Color::Red); text.setStyle(sf::Text::Bold | sf::Text::Underlined);
            text.setString(std::to_string(num));
            text.setPosition(pos, 70);
            num = num + 50;
            pos = pos + 50;
        }
        num = 10;
        pos = 57;
        // number of beats label assigned to vector
         for(int i = 5; i < 14; i++) {
            numTxt.push_back(text);
            text.setFont(font);   text.setCharacterSize(7.5);  text.setFillColor(sf::Color::Red); text.setStyle(sf::Text::Bold | sf::Text::Underlined);
            text.setString(std::to_string(num));
            text.setPosition(15, pos);
            num = num + 10;
            pos = pos - 7.5;
        }
         
         // other worded label
         text.setFont(font);   text.setCharacterSize(10);  text.setFillColor(sf::Color::Red); text.setStyle(sf::Text::Bold | sf::Text::Underlined); text.setString("HeartRate over time"); text.setPosition(117, -3);
         numTxt.push_back(text);
         text.setFont(font);   text.setCharacterSize(12);  text.setFillColor(sf::Color::Red); text.setStyle(sf::Text::Bold | sf::Text::Underlined); text.setString("time in seconds"); text.setPosition(130, 80);
         numTxt.push_back(text);
         text.setFont(font);   text.setCharacterSize(9);  text.setFillColor(sf::Color::Red); text.setStyle(sf::Text::Bold | sf::Text::Underlined); text.setString("H\ne\na\nr\nt\nR\na\nt\ne"); text.setPosition(1, 1);
         numTxt.push_back(text);
        

#pragma endregion
        
        window.clear();                                                 // Clear graphics buffer
        window.clear(sf::Color(255, 255, 255));                         // create a white background
        graphPts.drawPoints(window);                                    // Call draw function in my class
        
        // Display the graphics for the text 
        for (int i = 0; i < 17; i++) {
            window.draw(numTxt[i]);
        }
        window.display();                                               // Display the graphics from the buffer to the display

       


    }

    return 0;
}