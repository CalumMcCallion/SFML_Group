#pragma once
#include <vector>
#include <SFML/Graphics.hpp>                                            // sf namespace 
class graphPoints
{
private:
	std::vector<sf::CircleShape> points;
	std::vector<std::vector<std::string> > cords;
	std::vector<sf::RectangleShape>lines;
	std::vector<sf::RectangleShape>linesX;
	std::vector<sf::CircleShape> A;

	
	
	int gap = 1;
	float poss = 8;
	float temp = 0;
public:

	graphPoints();
	graphPoints(sf::CircleShape _shape);

	void loadPoints(std::string _fileName);
	void addPoint(sf::Color clr, float radius, sf::Vector2u origin, sf::Vector2f position);
	void setPointColor(int index, sf::Color _color);
	void clearPointList();
	void drawPoints(sf::RenderWindow &_win);
	void addLineY(sf::Color clr, int radius, sf::Vector2u origin, sf::Vector2f position);
	void addLineX(sf::Color clr, int radius, sf::Vector2u origin, sf::Vector2f position);
	void addAnchor(sf::Color clr, float radius, sf::Vector2u origin, sf::Vector2f position);
};

