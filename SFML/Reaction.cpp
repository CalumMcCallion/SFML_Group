#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 
#include "Reaction.h"

//--------------------------------------------------------creates assets-------------------------------------------
void Reaction::createButton(std::string _fileName) {
    if (!Button.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;
    ButtonImage.setTexture(Button);
    ButtonImage.setPosition(850, 350);
};



/*void Reaction::createStartButton1(std::string _fileName) {
    if (!REButton.loadFromFile(_fileName))
        std::cout << "Can't find the image" << std::endl;
    REButtonImage.setTexture(REButton);

};*/

void Reaction::creacteEndText(float time) {
    if (!font.loadFromFile("Pixel Cowboy.otf"))
    {
        // error...
    }

    text.setFont(font);   text.setCharacterSize(30);  text.setFillColor(sf::Color::Black); text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setString("points: " + std::to_string(points) + "\n" + "timer: " + std::to_string(time));
    text.setPosition(759, 250);

    // createStartButton1("title.PNG");
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

void Reaction::soundDelay(int ms) {
    while (TimerS.getElapsedTime().asMilliseconds() < ms);
}

void Reaction::loadBackgroundMusic(std::string music) {
    if (!buffer.loadFromFile(music))
    {
        std::cerr << "Error while loading sound file" << std::endl;

    }

    //"Mr Smith - Americana.mp3"
}

void Reaction::LoadSound(std::string gunshot) {

    if (!buffer.loadFromFile(gunshot))
    {
        std::cerr << "Error while loading sound file" << std::endl;

    }

}

void Reaction::PlaySound() {
    sound.setBuffer(buffer);
    sound.play();
    soundDelay(1500);

}

void Reaction::PlayMusic() {
    sound.setBuffer(buffer);
    music.play();
    soundDelay(1500);

}

//--------------------------------------Loads assets------------------------------------------------
void Reaction::startGame() {
    createButton("target1.png");
    createbackground("background2.png");
    createFakeButton("faketarget.png");
    loadBackgroundMusic("Mr Smith - Americana.wav");
    PlayMusic();
    LoadSound("gunshot.wav");
    clock.restart();
}

//-------------------------------------- mouse move funtions---------------------------------------------------
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
//-------------------------------------- mouse click funtions---------------------------------------------------
void Reaction::mouseButtonPressed(sf::RenderWindow& _win) {

    if (count != 21 && flag == true) {


        sf::Vector2i mousePos = sf::Mouse::getPosition(_win);
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        // fake button so if hit take away point
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


        // real target when hit add point
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

            PlaySound();
            points = points + 1;

        }
    }
    else {
        // a self locking if statement that grabs the time 
        if (flag == true) {
            ButtonImage.setPosition(-100, -100);
            fakeButtonImage.setPosition(-100, -100);
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

/*bool Reaction::REmouseButtonPressed(sf::RenderWindow& _win) {




        sf::Vector2i mousePos = sf::Mouse::getPosition(_win);
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        // fake button so if hit take away point

        if (REButtonImage.getGlobalBounds().contains(mousePosF))
        {
            return true;
        }
        else {
            return false;
        }



};*/


//--------------------------draw game-------------------------------------------
void Reaction::drawgame(sf::RenderWindow& _win) {


    _win.draw(text);
    _win.draw(backgroundImage);
    _win.draw(ButtonImage);
    _win.draw(fakeButtonImage);
    _win.draw(text);
    //  _win.draw(REButtonImage);





};
