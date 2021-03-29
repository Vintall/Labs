#include "Polygon.h"
#include <SFML/Graphics.hpp>

#include <iostream>

Polygon::Polygon(std::string name, Vector2f pos, float radius, int count)
{
	//this->name = name;
	Pos(pos);
	shape.switcher = 1;
	shape.conv = ConvexShape(count);
	float ang = 360 / count / 57.2958;
	Vector2f first_point = Vector2f(radius, 0);
	Vector2f point;
	for (int i = 0; i < count; i++)
	{
		point.x = first_point.x * cos(ang * i) + first_point.y * sin(ang * i);
		point.y = -1 * first_point.x * sin(ang * i) + first_point.y * cos(ang * i);
		shape.conv.setPoint(i, point);
	}
	shape.conv.setFillColor(Color::Blue);
	std::cout << shape.conv.getPointCount() << std::endl;
}
void Polygon::Pos(Vector2f _pos)
{
	pos = _pos;
	shape.conv.setPosition(pos);
	std::cout << shape.conv.getPosition().x << " " << shape.conv.getPosition().y << "Mark 1" << std::endl;
	
}