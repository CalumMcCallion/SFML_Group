#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 
#include "start.h"
#include "Reaction.h"

Reaction reaction;
void start::createStartButton1(std::string _fileName) {
    if (!startButton.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;
    startButtonImage.setTexture(startButton);
    startButtonImage.setPosition(0,0);
};


void start::mouseMoved(sf::RenderWindow& _win) {
    // getting pos of mouse
    sf::Vector2i mousePos = sf::Mouse::getPosition(_win);
    // changing the pos to be a Vector2f not a Vector2i
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    //if button isn't hovered over have it be white while hover be red (for testing if the bounderys are created can be removed later)
    if (startButtonImage.getGlobalBounds().contains(mousePosF))
    {
        startButtonImage.setColor(sf::Color(220, 220, 220));
    }
    else
    {
        startButtonImage.setColor(sf::Color(255, 255, 255));
    }

};

void start::CheckStart(std::string target, std::string faketarget, std::string background) {
    if (ReactionStart == true ) {
        reaction.createButton(target);
        reaction.createbackground(faketarget);
        reaction.createFakeButton(background);
        ReactionStart =false;
    }
}

void start::drawStart(sf::RenderWindow& _win) {
    _win.draw(startButtonImage);
};

void start::mouseButtonPressed(sf::RenderWindow& _win) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(_win);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    if (startButtonImage.getGlobalBounds().contains(mousePosF))
    {
        ReactionStart = true;
        starting = false;
        startButtonImage.setPosition(-10000, -10000);
    }
}