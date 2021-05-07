#pragma once
#include <SFML/Graphics.hpp>

class MyShape
{
public:
	sf::ConvexShape conv;
	sf::CircleShape circ;
	int switcher;
	//1 = poly    2 = circle     
};

