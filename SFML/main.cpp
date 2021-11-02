#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 

int main()
{
    // set the width and height so i can grab them vaules later
    int width = 1500;
    int height = 900;
    sf::RenderWindow window(sf::VideoMode(width, height), "reaction Game", sf::Style::Default);



    sf::Clock clock; // starts the clock
    sf::Texture Button;
    sf::Sprite ButtonImage;
    // grabbing an image for the button
    if (!Button.loadFromFile("target1.png"))
        std::cout << "Can't find the image" << std::endl;
    ButtonImage.setPosition(50.0f, 500.0f);

    //setting the buttons size based of the size of the image
    float ButtonWidth = ButtonImage.getLocalBounds().width;
    float ButtonHeight = ButtonImage.getLocalBounds().height;

    ButtonImage.setTexture(Button);

    // creating thew see for the radom number generater
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
                // getting pos of mouse
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
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
            }
            break;
            case sf::Event::MouseButtonPressed:
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
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
                    float randNumX = rand() % ((width- 200) - 50 + 1) + 50;
                    float randNumY = rand() % ((height-200) - 50 + 1) + 50;
                    //changes pos of button
                    ButtonImage.setPosition(randNumX, randNumY);
                }
            }
            break;
            }
        }

        window.clear();
        window.draw(ButtonImage);
        window.display();
    }
    return 0;
}