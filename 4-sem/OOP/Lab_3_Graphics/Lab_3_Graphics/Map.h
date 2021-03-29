#pragma once
#include <SFML/Graphics.hpp>
#include "Figure.h"
//#include "Polygon.h"
//#include "Circle.h"
//#include "Line.h"
#include <vector>
using namespace sf;
class Map
{
public:
	std::vector <Figure> obj;
	Map();
	void AddFigure(std::string name,Vector2f pos, int count, float radius);
	void AddFigure(std::string name, Vector2f pos, float radius);
	void AddFigure(std::string name, Vector2f p1, Vector2f p2);
};

