#pragma once
#include "Figure.h"
#include <SFML/Graphics.hpp>
#include "Prog_Manager.h"

class Polygon: public Figure
{
public:
	void Pos(Vector2f pos);
	Polygon(std::string name, Vector2f pos, float radius, int count);
};