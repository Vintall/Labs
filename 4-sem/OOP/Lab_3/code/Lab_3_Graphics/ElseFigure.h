#pragma once
#include "Figure.h"
#include <iostream>
class ElseFigure :public Figure
{
	public:
		ElseFigure(std::string name, std::vector<float> angles)
		{
			//this->name = name;
			//shape = ConvexShape(50);
			//
			//float ang = 360 / 50 / 57.2958f;
			//Vector2f first_point = Vector2f(radius, 0);
			//Vector2f point;
			//for (int i = 0; i < 50; i++)
			//{
			//	point.x = first_point.x * cos(ang * i) + first_point.y * sin(ang * i);
			//	point.y = -1 * first_point.x * sin(ang * i) + first_point.y * cos(ang * i);
			//	shape.setPoint(i, point);
			//}
			//shape.move(pos);
			//ChangeCol(0, 250, 0);
		}
		void SaySomething()
		{
			std::cout << "That's a new figure";
		}
};

