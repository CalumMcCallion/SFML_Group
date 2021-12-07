#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 
#include "start.h"
#include "Reaction.h"
#include "space.h"
#include "Tetris.h"
#include "mine.h"
#include "RPSS.h"
Reaction reaction;
space Space;
Tetris tetris;
mine Mine;
RPSS rps;
//============================================================ creating starting Buttons ==================================
//reactions
void start::createStartButton1(std::string _fileName){
    if (!startButton.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;
    startButtonImage.setTexture(startButton);
    startButtonImage.setPosition(400, 320);
    startButtonImage.setScale(0.47,0.47);
};
//space scroller game
void start::createStartButtonspace(std::string _fileName){
    if (!startButtonspace.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;
    startButtonspaceImage.setTexture(startButtonspace);
    startButtonspaceImage.setPosition(400, 460);
    startButtonspaceImage.setScale(1.172, 0.47);
};
//Tetris game 
void start::createStartButtonTetris(std::string _fileName){
    if (!startButtonTetris.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;
    startButtonTetrisImage.setTexture(startButtonTetris);
    startButtonTetrisImage.setPosition(400, 570);
    startButtonTetrisImage.setScale(0.47, 0.47);
};
void start::createStartButtonMine(std::string _fileName) {
    if (!startButtonMine.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;
    startButtonMineImage.setTexture(startButtonMine);
    startButtonMineImage.setPosition(400, 700);
    startButtonMineImage.setScale(0.47, 0.4);
};

void start::createStartButtonRPS(std::string _fileName) {
    if (!startButtonRPS.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;
    startButtonRPSImage.setTexture(startButtonRPS);
    startButtonRPSImage.setPosition(400, 800);
    startButtonRPSImage.setScale(0.47, 0.4);
};


//===========================================================Creating background===============================================
void start::createbackground(std::string _fileName) {
    // grabbing an image for the background
    if (!background.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;

    backgroundImage.setTexture(background);

};


//============================================================ when mouse moved ================================================
void start::mouseMoved(sf::RenderWindow& _win) {
    // getting pos of mouse
    sf::Vector2i mousePos = sf::Mouse::getPosition(_win);
    // changing the pos to be a Vector2f not a Vector2i
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    //highlights reaction game start
    if (startButtonImage.getGlobalBounds().contains(mousePosF))
    {
        startButtonImage.setColor(sf::Color(220, 220, 220));
    }
    else
    {
        startButtonImage.setColor(sf::Color(255, 255, 255));
    }
    
    
    //highlights space game start
    if (startButtonspaceImage.getGlobalBounds().contains(mousePosF))
    {
        startButtonspaceImage.setColor(sf::Color(220, 220, 220));
    }
    else
    {
        startButtonspaceImage.setColor(sf::Color(255, 255, 255));
    }
    
    
   //highlights Tetris game start
    if (startButtonTetrisImage.getGlobalBounds().contains(mousePosF))
    {
        startButtonTetrisImage.setColor(sf::Color(220, 220, 220));
    }
    else
    {
        startButtonTetrisImage.setColor(sf::Color(255, 255, 255));
    }

    //highlights minesweeper start
    if (startButtonMineImage.getGlobalBounds().contains(mousePosF))
    {
        startButtonMineImage.setColor(sf::Color(220, 220, 220));
    }
    else
    {
        startButtonMineImage.setColor(sf::Color(255, 255, 255));
    }
    //highlights RPS start
    if (startButtonRPSImage.getGlobalBounds().contains(mousePosF))
    {
        startButtonRPSImage.setColor(sf::Color(220, 220, 220));
    }
    else
    {
        startButtonRPSImage.setColor(sf::Color(255, 255, 255));
    }
};

//============================================================ when mouse clicked ==============================================
void start::mouseButtonPressed(sf::RenderWindow& _win) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(_win);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    if (startButtonImage.getGlobalBounds().contains(mousePosF))
    {
        ReactionStart = true;
        starting = false;
        startButtonImage.setPosition(-10000, -10000);
        startButtonspaceImage.setPosition(-10000, -10000);
        startButtonTetrisImage.setPosition(-10000, -10000);
        startButtonMineImage.setPosition(-10000, -10000);
        startButtonRPSImage.setPosition(-10000, -10000);
        backgroundImage.setPosition(-10000, -10000);
        
    }
    else if (startButtonspaceImage.getGlobalBounds().contains(mousePosF)) {
        sf::sleep(sf::milliseconds(300));
        Space.spaceGame(_win);
    
    }
    else if (startButtonTetrisImage.getGlobalBounds().contains(mousePosF)) {
        sf::sleep(sf::milliseconds(300));
        tetris.TetrisGame(_win);
        ReStart = true;

    }
    else if (startButtonMineImage.getGlobalBounds().contains(mousePosF)) {
        sf::sleep(sf::milliseconds(300));
        Mine.mineGame(_win);
        

    }
    else if (startButtonRPSImage.getGlobalBounds().contains(mousePosF)) {
        sf::sleep(sf::milliseconds(300));
        rps.RPSGame(_win);


    }


    
}


//============================================================ checking start ===================================================
void start::CheckStart(std::string target, std::string faketarget, std::string background) {
    if (ReactionStart == true) {
        reaction.createButton(target);
        reaction.createbackground(faketarget);
        reaction.createFakeButton(background);
        ReactionStart = false;
    }
}



//============================================================ drawing starting image ==========================================
void start::drawStart(sf::RenderWindow& _win) {
    
    _win.draw(backgroundImage);
    _win.draw(startButtonImage);
    _win.draw(startButtonspaceImage);
    _win.draw(startButtonTetrisImage);
    _win.draw(startButtonMineImage);
    _win.draw(startButtonRPSImage);
};

