#include "mine.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 



using namespace sf;
void mine::mineGame(sf::RenderWindow& app) {
    srand(time(0));

    //RenderWindow app(VideoMode(400, 400), "Minesweeper");

    int w = 32;
    int grid[12][12];
    int showGrid[36][36]; //for showing

    Texture t;
    t.loadFromFile("images/tiles.jpg");
    Sprite s(t);

    SoundBuffer click, whoosh; //declaring the sound effects
    if (!click.loadFromFile("sounds/click.wav")) {

                                                                     //Error handling - if file fails to load
    }

    if (!whoosh.loadFromFile("sounds/whoosh.wav")) {

       
    }

    Sound soundClick;                                                           //converting the sounds, so they can be used with the play function
    soundClick.setBuffer(click);

    Sound soundWhoosh;
    soundWhoosh.setBuffer(whoosh);

    //Background code added by Calum
    Texture b;
    b.loadFromFile("images/msbg.jfif");
    Sprite bg(b);
    bg.setPosition(0, 0);
    bg.setScale(1.3,1.3);

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            showGrid[i][j] = 10;
            if (rand() % 5 == 0)  grid[i][j] = 9;
            else grid[i][j] = 0;
        }

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            int n = 0;
            if (grid[i][j] == 9) continue;
            if (grid[i + 1][j] == 9) n++;
            if (grid[i][j + 1] == 9) n++;
            if (grid[i - 1][j] == 9) n++;
            if (grid[i][j - 1] == 9) n++;
            if (grid[i + 1][j + 1] == 9) n++;
            if (grid[i - 1][j - 1] == 9) n++;
            if (grid[i - 1][j + 1] == 9) n++;
            if (grid[i + 1][j - 1] == 9) n++;
            grid[i][j] = n;
        }

    while (app.isOpen())
    {
        
        Vector2i pos = Mouse::getPosition(app);
        int x = pos.x / w;
        int y = pos.y / w;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            //Window.close();
            break;
        }
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)                                        //Code to close app
                app.close();

            if (e.type == Event::MouseButtonPressed)                            //When left mouse is clicked it manipulates the grid and shows a tile
                if (e.key.code == Mouse::Left) {

                    showGrid[x][y] = grid[x][y];
                    soundClick.play();                                          //Click sound is played
                }
                else if (e.key.code == Mouse::Right) {                          //When right mouse is clicked it manipulates the grid and shows the flag tile

                    showGrid[x][y] = 11;
                    soundWhoosh.play();                                         //Whoosh sound is played
                }
        }

        app.clear(Color::White);
        //Background code added by Calum
        app.draw(bg);

        for (int i = 1; i <= 10; i++)
            for (int j = 1; j <= 10; j++)
            {
                if (showGrid[x][y] == 9) showGrid[i][j] = grid[i][j];
                s.setTextureRect(IntRect(showGrid[i][j] * w, 0, w, w));
                s.setPosition(i * w, j * w);
                
                app.draw(s);
                
                
            }
        
        app.display();
    }


}