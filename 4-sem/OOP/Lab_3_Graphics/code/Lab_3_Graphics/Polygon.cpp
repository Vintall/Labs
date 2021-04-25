#include "Polygon.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Polygon::Polygon(std::string name, Vector2f pos, float radius, int count)
{
	this->name = name;
	shape = ConvexShape(count);
	shape.setPosition(pos);
	float ang = 360 / count / 57.2958f;
	Vector2f first_point = Vector2f(radius, 0);
	Vector2f point;
	for (int i = 0; i < count; i++)
	{
		point.x = first_point.x * cos(ang * i) + first_point.y * sin(ang * i);
		point.y = -1 * first_point.x * sin(ang * i) + first_point.y * cos(ang * i);
		shape.setPoint(i, point);
	}
	ChangeCol(0, 250, 0);
}