#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 
#include "Reaction.h"

void Reaction::createButton(std::string _fileName) {
    if (!Button.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;
    ButtonImage.setPosition(50.0f, 500.0f);
    ButtonImage.setTexture(Button);
};

void Reaction::createbackground(std::string _fileName) {
    // grabbing an image for the background
    if (!background.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;

    backgroundImage.setTexture(background);

};

void Reaction::mouseMoved(sf::RenderWindow& _win) {
    // getting pos of mouse
    sf::Vector2i mousePos = sf::Mouse::getPosition(_win);
    // changing the pos to be a Vector2f not a Vector2i
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    //if button isn't hovered over have it be white while hover be red (for testing if the bounderys are created can be removed later)
    if (ButtonImage.getGlobalBounds().contains(mousePosF))
    {
        ButtonImage.setColor(sf::Color(250, 20, 20));
    }
    else
    {
        ButtonImage.setColor(sf::Color(255, 255, 255));
    }

};

void Reaction::mouseButtonPressed(sf::RenderWindow& _win) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(_win);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    if (ButtonImage.getGlobalBounds().contains(mousePosF))
    {
        //grabing time and resting the time to test the rection speed of each reaction 
        sf::Time elapsed1 = clock.getElapsedTime();
        std::cout << elapsed1.asSeconds() << std::endl;
        clock.restart();
        // prints out to the user they got a point (can be changed later)
        std::cout << "one point" << std::endl;
        // generating new x and y pos 
        float randNumX = rand() % ((width - 200) - 50 + 1) + 50;
        float randNumY = rand() % ((height - 200) - 50 + 1) + 50;
        //changes pos of button
        ButtonImage.setPosition(randNumX, randNumY);
    }

};





void Reaction::drawgame(sf::RenderWindow& _win) {



    _win.draw(backgroundImage);
    _win.draw(ButtonImage);





};
