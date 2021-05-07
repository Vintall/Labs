#pragma once
#include "Figure.h"
#include <SFML/Graphics.hpp>
#include "Prog_Manager.h"

class Star : public Figure
{
public:
	Star(std::string name, int ray_count, float r1, float r2);
};