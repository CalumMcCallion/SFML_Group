#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "graphPoints.h"

graphPoints::graphPoints() {};
graphPoints::graphPoints(sf::CircleShape _shape) {};

void graphPoints::loadPoints(std::string _fileName) {
    char co = ' ';
    std::cout << "what colour of dot R,G or B" << std::endl;
    std::cin >> co;
    
    
    std::ifstream dataStream;
    std::string line;

#pragma region CSV File Reading
    dataStream.open("HeartRate.csv");                                   // open file to a data stream for reading
    if (dataStream.is_open())                                           // check if file is open - e.g. it could be in the wrong folder
    {
        char next = dataStream.peek();                                  // take a peek at the next data character - i.e. only look, don't read
        while (next != EOF)                                             // if the next character is not the end of file then continue to read data
        {
            std::getline(dataStream, line);                             // get a line of text from the file
            std::stringstream lineStream(line);                         // create a line stream                      
            std::string character;
            std::vector<std::string> parsedRow;                         // a 2d vector - many rows of point co-ordinates                        
            while (std::getline(lineStream, character, ','))            // we  read a row at a time and parse it to get rid of the comma
            {
                parsedRow.push_back(character);                         // push a character at a time into the vector row (x and y co-ordinates)
                std::cout << std::stoi(character) << " ";               // print out to check
            }
            std::cout << std::endl;
            cords.push_back(parsedRow);                                 // push the parsed row into the vector list of co-ordinates

            next = dataStream.peek();                                   // take a sneek peek at the next character in case its the end of file character
        }

    }
    dataStream.close();
#pragma endregion

#pragma region Create Graph points 
    // add an SFML circle object (as a graph point) to our points vector list
// set positions of graph points from point co-ordinates loaded in from CSV file
    sf::Color color(0, 0, 0);
    if (co == 'R') {
        color.r = 255;
    }
    else if(co == 'G'){
        color.g = 255;
    }
    else {
        color.b = 255;
    }
    
    
    for (int i = 0; i < cords.size(); ++i) // for number of rows (300 in this example)
    {

        addAnchor(sf::Color(255, 0, 0), 0.5, sf::Vector2u(1, 1), sf::Vector2f(329, 75));
        addPoint(sf::Color(color), 0.5, sf::Vector2u(1, 1), sf::Vector2f(0, 0));
        addLineY(sf::Color(0, 0, 0), 1, sf::Vector2u(0, -25 ), sf::Vector2f(0, 25));
        addLineX(sf::Color(0, 0, 0), 0, sf::Vector2u(1, 1), sf::Vector2f(28, 60));
        
        for (int j = 0; j < cords[j].size(); ++j) // for number of columns (2)
        {
            sf::Vector2f position = A[0].getPosition();
            temp =   position.y-float(stoi(cords[i][j]));
        //  std::reverse(cords.begin(), cords.end());
            if (j == 0)  points[i].setPosition(sf::Vector2f(float(stoi(cords[i][j]) + 25), 0)); // x coordinate +++++++++++++++++++++++++++ side note added 25 to cords
          //std::reverse(cords.begin(), cords.end());
            if (j == 1) points[i].setPosition(sf::Vector2f(points[i].getPosition().x + gap * 2, temp+10)); // y coordinate
        
            if (i % 50==0) {
                if (j == 0) lines[i].setPosition(sf::Vector2f(float(stoi(cords[i][j]) + 25), 0)); // x coordinate for lines
                if (j == 1) lines[i].setPosition(sf::Vector2f(lines[i].getPosition().x + gap * 2, float(stoi(cords[0][0])))); // y coordinate for lines
            }
            // 121 = 50y, 6 = 60y , 78= 70;
            // 178  293  221
            // x = 23,
        }
        
    }
    for (int i = 0; i < 9; i++) {
        linesX[i].setPosition(sf::Vector2f(28, poss)); // y coordinate for lines
        poss = poss + 7.5;
    }
#pragma endregion
  
};
// adds points to the graph
void graphPoints::addPoint(sf::Color clr, float radius, sf::Vector2u origin, sf::Vector2f position) {
    sf::CircleShape pt; pt.setFillColor(clr); pt.setRadius(radius); pt.setOrigin(radius, radius); pt.setPosition(position);
    
    points.push_back(pt);
};

// adds the Y lines to the graph
void graphPoints::addLineY(sf::Color clr, int radius, sf::Vector2u origin, sf::Vector2f position) {
    sf::RectangleShape pR; pR.setFillColor(clr); pR.setSize(sf::Vector2f(1, 68)); pR.setOrigin(radius, radius); pR.setPosition(position);

    lines.push_back(pR);
};
// adds the X lines to the graph
void graphPoints::addLineX(sf::Color clr, int radius, sf::Vector2u origin, sf::Vector2f position) {
    sf::RectangleShape pR; pR.setFillColor(clr); pR.setSize(sf::Vector2f(0.5, 300)); pR.setOrigin(radius, radius); pR.setPosition(position); pR.setRotation(270);

    linesX.push_back(pR);
};

void graphPoints::addAnchor(sf::Color clr, float radius, sf::Vector2u origin, sf::Vector2f position) {
    sf::CircleShape pt; pt.setFillColor(clr); pt.setRadius(radius); pt.setOrigin(radius, radius); pt.setPosition(position);

    A.push_back(pt);
};

void graphPoints::setPointColor(int index, sf::Color _color) {};
void graphPoints::clearPointList() {};



void graphPoints::drawPoints(sf::RenderWindow &_win) {
    for (int i = 0; i < points.size(); ++i)
    {
        _win.draw(points[i]);
        _win.draw(lines[i]);
        _win.draw(linesX[i]);
        _win.draw(A[i]);
        
    }
   
    
   // _win.draw(Background[0]);
};