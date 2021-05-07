#pragma once
#include "Figure.h"
#include <SFML/Graphics.hpp>
class Line: public Figure
{
public:
	Line(std::string name, Vector2f pos, Vector2f p1, Vector2f p2);
	Vector2f point[2];
};

