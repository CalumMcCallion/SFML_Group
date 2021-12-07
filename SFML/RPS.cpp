#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 
#include "RPS.h"


//================================Building block====================================
// Mark help me with the function needed for create the window
//the feed back that when a button is click it will genurate what did CPU has pick
void RPS::createButton(std::string _fileName) {
    if (!Button.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;
    ButtonImage.setTexture(Button);
};
//this are to create all three button for user to pick
void RPS::createButtonR(std::string _fileName) {
    if (!ButtonR.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;
    ButtonImageR.setPosition(100, 300);
    ButtonImageR.setTexture(ButtonR);
};
void RPS::createButtonP(std::string _fileName) {
    if (!ButtonP.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;
    ButtonImageP.setPosition(400, 300);
    ButtonImageP.setTexture(ButtonP);
};
void RPS::createButtonS(std::string _fileName) {
    if (!ButtonS.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;
    ButtonImageS.setPosition(700, 300);
    ButtonImageS.setTexture(ButtonS);
};


void RPS::createbackground(std::string _fileName) {
    // grabbing an image for the background
    if (!background.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;

    backgroundImage.setTexture(background);
    backgroundImage.setScale(1.5,1.5);

};

//==============================Game Over===================================================
void RPS::gameover() {
    if (!font.loadFromFile("fonts/arial.ttf")) {
        //error
    }
    gameOver.setFont(font); gameOver.setCharacterSize(400); gameOver.setFillColor(sf::Color::Red); gameOver.setStyle(sf::Text::Bold);
    if (life == 0)
    {
        gameOver.setString("You Lose");
    }
    else {
        gameOver.setString("You win ");
    }

    textL.setPosition(500, 500);

}
//=================================Mouse Action===========================================
void RPS::mouseMoved(sf::RenderWindow& _win) {
    // getting pos of mouse
    sf::Vector2i mousePos = sf::Mouse::getPosition(_win);
    // changing the pos to be a Vector2f not a Vector2i
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    //if button isn't hovered over have it be white while hover be little darker (for player to know if the mouse is on the bounderys)
    if (ButtonImage.getGlobalBounds().contains(mousePosF))
    {
        ButtonImage.setColor(sf::Color(220, 220, 220));
    }
    else
    {
        ButtonImage.setColor(sf::Color(255, 255, 255));
    }
    if (ButtonImageR.getGlobalBounds().contains(mousePosF))
    {
        ButtonImageR.setColor(sf::Color(220, 220, 220));
    }
    else
    {
        ButtonImageR.setColor(sf::Color(255, 255, 255));
    }
    if (ButtonImageS.getGlobalBounds().contains(mousePosF))
    {
        ButtonImageS.setColor(sf::Color(220, 220, 220));
    }
    else
    {
        ButtonImageS.setColor(sf::Color(255, 255, 255));
    }
    if (ButtonImageP.getGlobalBounds().contains(mousePosF))
    {
        ButtonImageP.setColor(sf::Color(220, 220, 220));
    }
    else
    {
        ButtonImageP.setColor(sf::Color(255, 255, 255));
    }

};

void RPS::mouseButtonPressed(sf::RenderWindow& _win) {
      //0 is wand which is Paper, 1 is archery which is Scissors and 2 is Sword which is Rock 
      
      //using random number to genurate the reaction for the CPU
 
    int randNumZ = rand() % 3;



    sf::Vector2i mousePos = sf::Mouse::getPosition(_win);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    
    //Three if statement to compare all the possible outcome
    if (ButtonImageR.getGlobalBounds().contains(mousePosF))
    {
        if (randNumZ == 0)
        {
            createButton("images/magician wand.png");
            ButtonImage.setPosition(1000, (height / 2));
            std::cout << "YouLose" << std::endl;
            life = life - 1;
        }
        if (randNumZ == 1)
        {
            createButton("images/bow-arrow.png");
            ButtonImage.setPosition(1000, (height / 2));
            std::cout << "YouWin" << std::endl;
            eLife = eLife - 1;
        }
        if (randNumZ == 2)
        {
            createButton("images/Sword.png");
            ButtonImage.setPosition(1000, (height / 2));
            std::cout << "DrawGame" << std::endl;
        }
    }

    else if (ButtonImageS.getGlobalBounds().contains(mousePosF)) {
        if (randNumZ == 0)
        {
            createButton("images/magician wand.png");
            ButtonImage.setPosition(1000, (height / 2));
            std::cout << "YouWin" << std::endl;
            eLife = eLife - 1;
        }


        if (randNumZ == 1)
        {
            createButton("images/bow-arrow.png");
            ButtonImage.setPosition(1000, (height / 2));
            std::cout << "DrawGame" << std::endl;
        }


        if (randNumZ == 2)
        {
            createButton("images/Sword.png");
            ButtonImage.setPosition(1000, (height / 2));
            std::cout << "YouLose" << std::endl;
            life = life - 1;
        }

    }
    else if (ButtonImageP.getGlobalBounds().contains(mousePosF)) {
        if (randNumZ == 0)
        {
            createButton("images/magician wand.png");
            ButtonImage.setPosition(1000, (height / 2));
            std::cout << "DrawGame" << std::endl;
        }

        if (randNumZ == 1)
        {
            createButton("images/bow-arrow.png");
            ButtonImage.setPosition(1000, (height / 2));
            std::cout << "YouLose" << std::endl;
            life = life - 1;
        }
        if (randNumZ == 2)
        {
            createButton("images/Sword.png");
            ButtonImage.setPosition(1000, (height / 2));
            std::cout << "YouWin" << std::endl;
            eLife = eLife - 1;
        }
    }


    //Determin when is the game over

    if (life == 0 || eLife == 0) {
        gameover();
    }
};

// ==========================================Text=====================================================================
// Calum help me with the code to check did I set the address of the font
// Display the Player life Point
void RPS::displayTextL() {
    if (!font.loadFromFile("fonts/arial.ttf")) {
        //error
    }
    textL.setFont(font); textL.setCharacterSize(30); textL.setFillColor(sf::Color::White); textL.setStyle(sf::Text::Bold);
    textL.setString("Your Lifes: " + std::to_string(life));
    textL.setPosition(100, 0);




};
// Display the Eneimy life Point
void RPS::displayTextR() {
    if (!font.loadFromFile("fonts/arial.ttf")) {
        //error
    }
    textR.setFont(font); textR.setCharacterSize(30); textR.setFillColor(sf::Color::White); textR.setStyle(sf::Text::Bold);
    textR.setString("Enemy's Lifes: " + std::to_string(eLife));
    textR.setPosition(1500, 0);




};


//============================================= music =====================================================
//since that it has no error during build but it not play the music, Mark has help me with the function to let the music working 
void RPS::soundDelay(int ms) {
    while (TimerS.getElapsedTime().asMilliseconds() < ms);
}


void RPS::loadBackgroundMusic(std::string musicN) {
    if (!music.openFromFile(musicN))
    {
        std::cerr << "Error while loading sound file" << std::endl;

    }



    //"BOG CREATURES ON THE MOVE.mp3"
}

void RPS::PlayMusic() {
    music.play();
    soundDelay(1500);

}






void RPS::drawgame(sf::RenderWindow& _win) {



    _win.draw(backgroundImage);
    _win.draw(ButtonImage);
    _win.draw(ButtonImageR);
    _win.draw(ButtonImageS);
    _win.draw(ButtonImageP);
    _win.draw(textL);
    _win.draw(textR);
    _win.draw(gameOver);





};
