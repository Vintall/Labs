#include "Star.h"

Star::Star(std::string name, int ray_count, float r1, float r2)
{
	this->name = name;
	shape = ConvexShape(ray_count * 2);
	shape.setPosition(0, 0);
	float ang = 360 / (ray_count * 2) / 57.2958f;
	Vector2f first_point = Vector2f(r1, 0);
	Vector2f second_point = Vector2f(r2, 0);
	Vector2f point;
	for (int i = 0; i < ray_count * 2; i++)
	{
		if (i % 2 == 0)
		{
			point.x = first_point.x * cos(ang * i) + first_point.y * sin(ang * i);
			point.y = -1 * first_point.x * sin(ang * i) + first_point.y * cos(ang * i);
			shape.setPoint(i, point);
		}
		else
		{
			point.x = second_point.x * cos(ang * i) + second_point.y * sin(ang * i);
			point.y = -1 * second_point.x * sin(ang * i) + second_point.y * cos(ang * i);
			shape.setPoint(i, point);
		}
	}
	ChangeCol(0, 250, 0);
}