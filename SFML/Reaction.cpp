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
    ButtonImage.setTexture(Button);
    ButtonImage.setPosition(850, 350);
};

void Reaction::creacteEndText(float time) {
    if (!font.loadFromFile("arial.ttf"))
    {
        // error...
    }
    text.setFont(font);   text.setCharacterSize(30);  text.setFillColor(sf::Color::Black); text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setString("points: " + std::to_string(points) + "\n" + "timer: " + std::to_string(time));
    text.setPosition(850, 350);
};

void Reaction::createFakeButton(std::string _fileName) {
    if (!fakeButton.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;
    fakeButtonImage.setTexture(fakeButton);
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

    if (count != 20 && flag == true) {


        sf::Vector2i mousePos = sf::Mouse::getPosition(_win);
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        if (count % 4 == 0) {
            float randNumX = rand() % ((width - 200) - 50 + 1) + 50;
            float randNumY = rand() % ((height - 200) - 50 + 1) + 50;
            fakeButtonImage.setPosition(randNumX, randNumY);
        }
        else {
            fakeButtonImage.setPosition(-100, -100);
        }

        if (fakeButtonImage.getGlobalBounds().contains(mousePosF))
        {
            points = points - 1;
        }



        if (ButtonImage.getGlobalBounds().contains(mousePosF))
        {


            //grabing time and resting the time to test the rection speed of each reaction 
            sf::Time elapsed1 = clock.getElapsedTime();
            std::cout << elapsed1.asSeconds() << std::endl;
            clock.restart();
            // generating new x and y pos 
            float randNumX = rand() % ((width - 200) - 50 + 1) + 50;
            float randNumY = rand() % ((height - 200) - 50 + 1) + 50;
            //changes pos of button
            ButtonImage.setPosition(randNumX, randNumY);


            points = points + 1;

        }
    }
    else {
        if (flag == true) {
            ButtonImage.setPosition(-100, -100);
            sf::Time elapsed2 = clock1.getElapsedTime();
            creacteEndText(elapsed2.asSeconds());
            std::cout << "time elapsed: " << elapsed2.asSeconds() << std::endl;
            std::cout << "no. of points: " << points << std::endl;
            _win.draw(text);
            flag = false;
        }
    }

    count = count + 1;
};




void Reaction::drawgame(sf::RenderWindow& _win) {


    _win.draw(text);
    _win.draw(backgroundImage);
    _win.draw(ButtonImage);
    _win.draw(fakeButtonImage);





};
