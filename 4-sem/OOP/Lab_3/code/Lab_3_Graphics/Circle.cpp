#include "Circle.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
Circle::Circle(std::string name, Vector2f pos, float radius)
{
	this->name = name;
	shape = ConvexShape(50);

	float ang = 360 / 50 / 57.2958f;
	Vector2f first_point = Vector2f(radius, 0);
	Vector2f point;
	for (int i = 0; i < 50; i++)
	{
		point.x = first_point.x * cos(ang * i) + first_point.y * sin(ang * i);
		point.y = -1 * first_point.x * sin(ang * i) + first_point.y * cos(ang * i);
		shape.setPoint(i, point);
	}
	shape.move(pos);
	ChangeCol(0, 250, 0);
}