#pragma once
#include "Figure.h"
#include <SFML/Graphics.hpp>
class Circle: public Figure
{
public:
	Circle();
	float radius;
	Circle(std::string name, Vector2f pos, float radius);
};