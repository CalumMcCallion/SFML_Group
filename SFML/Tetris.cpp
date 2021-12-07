#include "Tetris.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 

#include <time.h>


using namespace sf; // defines the SFML namespace for later use in the code


const int M = 20; //Initialises the constants that will be used in an array throughout the program to manipulate the blocks
const int N = 10;




int field[M][N] = { 0 };





void Tetris::setup() {
    struct Point
    {
        int x, y;
    } a[4], b[4];
    
    
    int figures[7][4] = // This defines the shape of the different tetremominoes 
    {
        1,3,5,7, // I
        2,4,5,7, // Z
        3,5,4,6, // S
        3,5,4,7, // T
        2,3,5,7, // L
        3,5,7,6, // J
        2,3,4,5, // O
    };
    
    

    
};

bool Tetris::check(){
    for (int i = 0; i < 4; i++)
        if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
        else if (field[a[i].y][a[i].x]) return 0;

    return 1;
};



void Tetris::TetrisGame(sf::RenderWindow& window){
    setup();
    int points = 0;
    sf::Time elapsed_time; // this time will be used to end the game when the blocks reach the top of the frame
    sf::Clock r;
    srand(time(0));

    //RenderWindow window(VideoMode(320, 480), "Tetro!"); //Creates the window

    Texture t1, t2, t3, t4; //Creates the textures that will be used for the tiles, frame, and background
    t1.loadFromFile("images/tiles.png");
    t2.loadFromFile("images/background.png");
    t3.loadFromFile("images/frame.png");
    t4.loadFromFile("images/Game_Over.png");

    Sprite s(t1), background(t2), frame(t3), gameOver(t4); //Changes the tetures into sprites

    sf::Music music; // Loads the background music that will play as the game runs
    if (!music.openFromFile("audio/Tetris.wav")) {
        
    }

    sf::SoundBuffer buffer; //Loads the sound that will play when the player clears a line
    if (!buffer.loadFromFile("audio/SFX_SpecialLineClearTriple.wav")) {
        
    }

    music.play();
    music.setLoop(true); //Plays the music and loops it so it continues to play if the player plays the game for longer than the length of music
    int dx = 0; bool rotate = 0; int colorNum = 1;
    float timer = 0, delay = 0.3;

    Clock clock;
    int score = 0;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();

            if (e.type == Event::KeyPressed)
                if (e.key.code == Keyboard::Up) rotate = true;
                else if (e.key.code == Keyboard::Left) dx = -1; //Moves the blocks to the left when the left arrow key is pressed
                else if (e.key.code == Keyboard::Right) dx = 1; //Moves the blocks to the right when the right arrow key is pressed
        }

        if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05; //Moves the blocks down faster when the down arrow key is pressed

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            //Window.close();
            break;
        }

        //// <- Move -> ///
        for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].x += dx; }
        if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];

        //////Rotate//////
        if (rotate)
        {
            Point p = a[1]; //center of rotation
            for (int i = 0; i < 4; i++)
            {
                int x = a[i].y - p.y;  //Rotates the blocks when the up arrow key is pressed
                int y = a[i].x - p.x;
                a[i].x = p.x - x;
                a[i].y = p.y + y;
            }
            if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];
        }

        ///////Tick//////
        if (timer > delay)
        {
            for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }

            if (!check())
            {
                sf::Time delta_time = sf::milliseconds(300); // Mark helped me figure this out, when a block is created a timer is started, if the timer lasts less than a seconnd
                elapsed_time = r.restart(); //i.e. if a new block is created less than a second after the previous one the blocks are at the top of the frame and the game will end
                if (elapsed_time <= delta_time) {
                    //  bool endscreenFlag = true;
                    break;
                }

                for (int i = 0; i < 4; i++) field[b[i].y][b[i].x] = colorNum;

                colorNum = 1 + rand() % 7; // this randomises the colour of the blocks so that every block will not be the same colour 
                int n = rand() % 7;
                for (int i = 0; i < 4; i++)
                {
                    a[i].x = figures[n][i] % 2;
                    a[i].y = figures[n][i] / 2;
                }
            }

            timer = 0;
        }

        ///////check lines//////////
        int k = M - 1;
        for (int i = M - 1; i > 0; i--) // this code checks if the player has made a line with the blocks and removes the line
        {
            int count = 0;
            for (int j = 0; j < N; j++)
            {
                if (field[i][j]) count++;
                field[k][j] = field[i][j];
            }
            if (count < N) {
                k--;
            }
        }

        dx = 0; rotate = 0; delay = 0.3;

        ///Scoring
        if (k--) {
            score = score + 100; //if a line has been cleared 100 points will be added and the sound will play
            sf::Sound lineClear;
            lineClear.setBuffer(buffer);
            lineClear.play();
            while (k--) {
                points = points + 100;



            }
        }

        sf::Font sc;

        if (!sc.loadFromFile("Fonts/ARCADE_I.TTF"))
        {

        }


        //High Scoring//
        int highScore = 0;
        if (highScore <= score) {

            highScore = highScore + 100;
        }


        //End Game//
        /*Plan to have code that ends game and displays high score when tiles hit top of frame
        if (bool endscreenFlag = true) {

            window.draw(gameOver);

        }*/

        /////////draw//////////
        window.clear(Color::White); //draws the blank white window
        window.draw(background); //draws the background sprite over the blank window 

        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
            {
                if (field[i][j] == 0) continue;
                s.setTextureRect(IntRect(field[i][j] * 18, 0, 18, 18));
                s.setPosition(j * 18, i * 18);
                s.move(28, 31); //offset
                window.draw(s);
            }

        for (int i = 0; i < 4; i++)
        {
            s.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
            s.setPosition(a[i].x * 18, a[i].y * 18);
            s.move(28, 31); //offset
            window.draw(s);
        }



        sf::Text scoring;
        scoring.setFont(sc); //draws the player's score on the window
        scoring.setCharacterSize(24);
        scoring.setFillColor(sf::Color::Red);
        scoring.setString(" Score: " + std::to_string(score));
        scoring.setPosition(30, 40);

        sf::Text highScoring;
        highScoring.setFont(sc);
        highScoring.setString(" High Score: " + std::to_string(highScore));
        highScoring.setCharacterSize(24);
        highScoring.setFillColor(sf::Color::Red);
        highScoring.setPosition(10, 100.);

        window.draw(frame); //drwas the frame
        window.draw(scoring); // draws the points 
       // window.draw(highScoring);
        window.display(); // dispays the window 

    }

}